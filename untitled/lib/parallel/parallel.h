#ifndef LIB_PARALLEL_PARALLEL_H_
#define LIB_PARALLEL_PARALLEL_H_

#include "segment.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include "string.h"
#include "utils.h"

int parallel(const char *file_with_names, const char *file_with_mailers, const char *file_with_recipients,
              const char *file_with_topic, const char *file_with_letter, const char *file_with_date,
              char *result_name, int size_letters, int size_mailer,  char date_start[11],
             char date_finish[11]);

int input_segments(segment *segments, long child_count, int segment_size);

int segment_processing(Letters *letters, Names *names, segment *segments, int child_count, int size_mailer,
                       char date_start[11], char date_finish[11]);

int search_max(Names *names, segment *segments, int child_count, char result_name[30], int size_mailer);

#endif  // LIB_PARALLEL_PARALLEL_H_
