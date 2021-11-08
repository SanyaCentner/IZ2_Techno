#ifndef UNTITLED_LIB_PARALLEL_SEGMENT_H_
#define UNTITLED_LIB_PARALLEL_SEGMENT_H_

typedef struct segment {
    int begin;
    int end;
    int number_of_shipments[10000];
    int use;
}segment;
#endif  // UNTITLED_LIB_PARALLEL_SEGMENT_H_
