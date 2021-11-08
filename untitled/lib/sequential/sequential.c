#include "sequential.h"
#include "utils.h"

int sequential(const char *file_with_names, const char *file_with_mailers, const char *file_with_recipients,
               const char *file_with_topic, const char *file_with_letter, const char *file_with_date,
               char *result_name, int size_letters, int size_mailer, char date_start[11],
               char date_finish[11]) {
    Letters *letters = input_letters(file_with_mailers, file_with_recipients, file_with_topic,
                                     file_with_letter, file_with_date, size_letters);
    Names *names = input_names(file_with_names, size_mailer);
    if (max_sequence(letters, names, result_name, size_letters, size_mailer, date_start,
                     date_finish) == EXIT_FAILURE) {
        free(names);
        free(letters);
        return EXIT_FAILURE;
    }
    free(letters);
    free(names);
    return EXIT_SUCCESS;
}

