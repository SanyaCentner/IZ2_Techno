#ifndef LIB_SEQUENTIAL_SEQUENTIAL_H_
#define LIB_SEQUENTIAL_SEQUENTIAL_H_

#include <stdlib.h>

int sequential(const char *file_with_names, const char *file_with_mailers, const char *file_with_recipients,
               const char *file_with_topic, const char *file_with_letter, const char *file_with_date,
               char *result_name, int size_letters, int size_mailer, char date_start[11],
               char date_finish[11]);

#endif  // LIB_SEQUENTIAL_SEQUENTIAL_H_

