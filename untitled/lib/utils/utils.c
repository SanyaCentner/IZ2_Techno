#include "utils.h"


Letters *input_letters(const char *file_with_mailers, const char *file_with_recipients,
                       const char *file_with_topic, const char *file_with_letter, const char *file_with_date,
                       int size_symbols) {
    Letters *letters = (Letters*) malloc(size_symbols * sizeof(Letter));
    if (letters == NULL) {
        printf("Нет памяти");
        return -1;
    }
    letters->count = size_symbols;
    FILE *f;
    f = fopen(file_with_mailers, "r");
    if (f == 0) {
        printf("Can't open file");
        return EXIT_FAILURE;
    }
    int line_number = 0;
    while (!feof(f)) {
        Letter *letter = &(letters->letters[line_number]);
        if (letter == NULL) {
            printf("Нет памяти");
            return -1;
        }
        fgets(letter->mailer, 25, f);
        line_number++;
    }
    fclose(f);

    FILE *f1;
    f1 = fopen(file_with_recipients, "r");
    if (f1 == 0) {
        printf("Can't open file");
        return EXIT_FAILURE;
    }
    int line_number1 = 0;
    while (!feof(f1)) {
        Letter *letter = &(letters->letters[line_number1]);
        if (letter == NULL) {
            printf("Нет памяти");
            return -1;
        }
        fgets(letter->recipients, 64, f1);
        line_number1++;
    }
    fclose(f1);

    FILE *f2;
    f2 = fopen(file_with_topic, "r");
    if (f2 == 0) {
        printf("Can't open file");
        return EXIT_FAILURE;
    }
    int line_number2 = 0;
    while (!feof(f2)) {
        Letter *letter = &(letters->letters[line_number2]);
        if (letter == NULL) {
            printf("Нет памяти");
            return -1;
        }
        fgets(letter->topic, 16, f2);
        line_number2++;
    }
    fclose(f2);

    FILE *f3;
    f3 = fopen(file_with_letter, "r");
    if (f3 == 0) {
        printf("Can't open file");
        return EXIT_FAILURE;
    }
    int line_number3 = 0;
    while (!feof(f3)) {
        Letter *letter = &(letters->letters[line_number3]);
        if (letter == NULL) {
            printf("Нет памяти");
            return -1;
        }
        fgets(letter->body_of_letter, 100, f3);
        line_number3++;
    }
    fclose(f3);

    FILE *f4;
    f4 = fopen(file_with_date, "r");
    if (f == 0) {
        printf("Can't open file");
        return EXIT_FAILURE;
    }
    int line_number4 = 0;
    while (!feof(f4)) {
        Letter *letter = &(letters->letters[line_number4]);
        if (letter == NULL) {
            printf("Нет памяти");
            return -1;
        }
        fgets(letter->date, 12, f4);
        line_number4++;
    }
    fclose(f4);

    return letters;
}

Names *input_names(const char *file_with_names, int size_symbols) {
    Names *names = (Names*) malloc(size_symbols * sizeof(Name));
    if (names == NULL) {
        printf("Нет памяти");
        return -1;
    }
    names->count = size_symbols;
    FILE *f;
    f = fopen(file_with_names, "r");
    if (f == 0) {
        printf("Can't open file");
        return -1;
    }
    int line_number = 0;
    while (!feof(f)) {
        Name *name = &(names->names[line_number]);
        fgets(name->name, 25, f);
        line_number++;
    }
    fclose(f);
    return names;
}

int max_sequence(Letters *letters, Names *names, char result_name[25], int size_letters, int size_mailer,
                 char data_start[12], char data_finish[12]) {
    int number[10000] = {};

    for (int i = 0; i < size_mailer; i++) {
        int max = 0;
        Name name = names->names[i];
        for (int j = 0; j < size_letters; j++) {
            Letter letter = letters->letters[j];
            if (comparasion_date(data_start, data_finish, letter.date) == 0) {
                if (strcmp(letter.mailer, name.name) == 0) {
                    max++;
                }
            }
        }
        number[i] = max;
    }
    int number_of_max = maximum(number, size_mailer);
    Name name = names->names[number_of_max];
    strcpy(result_name, name.name);
    return 0;
}

int comparasion_date(char data_start[12], char date_finish[12], char *date) {
    if ((atoi(data_start) <= atoi(date)) && (atoi(date_finish) >= atoi(date))) {
        return 0;
    } else {
        return -1;
    }
}

int print_date(const char* msg, char* date) {
    printf("%s", msg);
    if (scanf("%11s", date) < 0) {
        return -1;
    }
    return 0;
}

int maximum(int *maxim, int size_mailer) {
    int max = 0;
    int number_of_max = 0;
    int k = 0;
    for (int i = 0; i < size_mailer; i++) {
        if (maxim[i] > max) {
            max = maxim[i];
            k = i;
            number_of_max = k;
        }
    }
    return number_of_max;
}

int max_parallel(Letters *letters, Names *names, int begin, int end, int result_name[10000],
                 int size_mailer, char data_start[11], char data_finish[11]) {
    for (int i = 0; i < size_mailer; i++) {
        int max = 0;
        Name name = names->names[i];
        for (int j = begin; j <= end; j++) {
            Letter letter = letters->letters[j];
            if (comparasion_date(data_start, data_finish, letter.date) == 0) {
                if (strcmp(letter.mailer, name.name) == 0) {
                    max++;
                }
            }
        }
        result_name[i] = max;
    }
    return EXIT_SUCCESS;
}
