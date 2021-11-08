#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "sequential.h"
#include "parallel.h"

int main(int argc, char const* argv[]) {
    char result_sequential[25] = {};
    const char *file_with_mailers;
    file_with_mailers = "mailer.txt";
    const char *file_with_names;
    file_with_names = "names.txt";
    const char *file_with_recipients;
    file_with_recipients = "recipients.txt";
    const char *file_with_topic;
    file_with_topic = "topic.txt";
    const char *file_with_letter;
    file_with_letter = "letter.txt";
    const char *file_with_date;
    file_with_date = "date.txt";
    char date_start[12];
    char date_finish[12];
    printf("Минимальная дата - 2012.1.1\n");
    printf("Конечная дата - 2021.1.1\n");
    int start = print_date("Введите дату начала:\n", &date_start);
    if (start < 0) {
        return EXIT_FAILURE;
    }
    int end = print_date("Введите дату конца:\n", &date_finish);
    if (end < 0) {
        return EXIT_FAILURE;
    }
    double start_sequential = clock();

    if (sequential(file_with_names, file_with_mailers, file_with_recipients, file_with_topic,
                   file_with_letter, file_with_date, result_sequential, 1000000,
                   10000, date_start, date_finish) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    double finish_sequential = clock();

    printf("Sequential. Time: %lf\n", (finish_sequential - start_sequential) / CLOCKS_PER_SEC);
    printf("Максимальное количество отправлений у пользователя %s", result_sequential);

    char result_parallel[25]={};

    double start_parallel = clock();

    if (parallel(file_with_names, file_with_mailers, file_with_recipients, file_with_topic,
                   file_with_letter, file_with_date, result_parallel, 1000000,
                   10000, date_start, date_finish) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    double finish_parallel = clock();

    printf("Parallel. Time: %lf\n", (finish_parallel - start_parallel) / CLOCKS_PER_SEC);
    printf("Максимальное количество отправлений у пользователя %s", result_parallel);
    return EXIT_SUCCESS;
}
