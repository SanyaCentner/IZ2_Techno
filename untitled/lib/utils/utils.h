#ifndef LIB_UTILS_UTILS_H_
#define LIB_UTILS_UTILS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define letter_max_len  1000000
#define name_max_len  10000
typedef struct Letter {
    char mailer[25];
    char recipients[72];
    char topic[16];
    char body_of_letter[100];
    char date[12];
}Letter;

typedef struct Letters {
    int count;
    Letter letters[letter_max_len];
}Letters;

typedef struct Name {
    char name[25];
}Name;
typedef struct Names {
    int count;
    Name names[name_max_len];
}Names;

Letters *input_letters(const char *file_with_mailers, const char *file_with_recipients,
                       const char *file_with_topic, const char *file_with_letter, const char *file_with_date,
                       int size_symbols);

Names *input_names(const char *file_with_names, int size_symbols);

int max_sequence(Letters *letters, Names *names, char result_name[30], int size_letters, int size_mailer,
                 char data_start[11], char data_finish[11]);

int comparasion_date(char data_start[11], char date_start[11],char *date);

int print_date(const char* msg, char* date);

int maximum(int *maxim, int size_mailer);

int max_parallel(Letters *letters, Names *names, int begin, int end, int result_name[10000],
                 int size_mailer, char data_start[11], char data_finish[11]);

#endif  // LIB_UTILS_UTILS_H_
