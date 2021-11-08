#include "parallel.h"
#include "utils.h"

int parallel(const char *file_with_names, const char *file_with_mailers, const char *file_with_recipients,
              const char *file_with_topic, const char *file_with_letter, const char *file_with_date,
              char *result_name, int size_letters, int size_mailer,  char date_start[11],
             char date_finish[11]) {
    int child_count = sysconf(_SC_NPROCESSORS_ONLN);
    Letters *letters = input_letters(file_with_mailers, file_with_recipients, file_with_topic,
                                     file_with_letter, file_with_date, size_letters);
    Names *names = input_names(file_with_names, size_mailer);
    int segment_size = size_letters / child_count;
    segment *segments = mmap(NULL, child_count * sizeof(segment), PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (segments == MAP_FAILED) {
        free(letters);
        free(names);
        return EXIT_FAILURE;
    }

    if (input_segments(segments, child_count, segment_size) == EXIT_FAILURE) {
        free(letters);
        free(names);
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    for (size_t i = 0; i < child_count - 2; ++i) {
        if (pid != 0) {
            pid = fork();
        }
    }

    if (segment_processing(letters, names, segments, child_count, size_mailer, date_start,
                           date_finish) == EXIT_FAILURE) {
        if (pid != 0) {
            munmap(segments, child_count);
            free(letters);
            free(names);
            return EXIT_FAILURE;
        } else {
            exit(EXIT_FAILURE);
        }
    } else if (pid == 0) {
        exit(EXIT_SUCCESS);
    }
    int status = 0;
    if (pid > 0) {
        for (int i = 0; i < child_count - 1; ++i) {
            wait(&status);
            if (status == -1) {
                puts("Process error");
            }
        }
    }
    if (search_max(names, segments, child_count, result_name, size_mailer) == EXIT_FAILURE) {
        munmap(segments, child_count);
        free(letters);
        free(names);
        return EXIT_FAILURE;
    }
    munmap(segments, child_count);
    free(names);
    free(letters);
    return EXIT_SUCCESS;
}


int input_segments(segment *segments, long child_count,
                   int segment_size) {
    for (long i = 0; i < child_count; ++i) {
        if (i == 0) {
            segments[i].begin = 0;
            segments[i].end = segment_size - 1;
        } else {
            segments[i].begin = segments[i - 1].end + 1;
            segments[i].end = segments[i].begin + segment_size - 1;
        }
        segments[i].use = 0;
    }
    return EXIT_SUCCESS;
}

int segment_processing(Letters *letters, Names *names, segment *segments, int child_count, int size_mailer,
                       char date_start[12], char date_finish[12]) {
    for (int i = 0; i < child_count; ++i) {
        if (segments[i].use == 0) {
            segments[i].use = 1;
            if (max_parallel(letters, names, segments[i].begin, segments[i].end,
                             segments[i].number_of_shipments, size_mailer, date_start,
                             date_finish) == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

int search_max(Names *names, segment *segments, int child_count, char result_name[30], int size_mailer) {
    int result_max[10000] = {};
    for (int i = 0; i < child_count; ++i) {
        for (int j = 0; j < size_mailer; j++) {
            result_max[j] += segments[i].number_of_shipments[j];
        }
    }
    int number_of_max = maximum(result_max, size_mailer);
    Name name = names->names[number_of_max];
    strcpy(result_name, name.name);
    return EXIT_SUCCESS;
}

