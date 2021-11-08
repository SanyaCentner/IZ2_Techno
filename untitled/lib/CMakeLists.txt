cmake_minimum_required(VERSION 3.20)

set(SOURCE_FILES_SEQ "sequential/sequential.c" "utils/utils.c")
set(HEADER_FILES_SEQ "sequential/sequential.h" "utils/utils.h")

set(SOURCE_FILES_PAR "parallel/parallel.c" "utils/utils.c")
set(HEADER_FILES_PAR "parallel/parallel.h" "parallel/segment.h" "utils/utils.h")

add_library(sequential_lib STATIC ${HEADER_FILES_SEQ} ${SOURCE_FILES_SEQ} )
add_library(parallel_lib SHARED ${HEADER_FILES_PAR} ${SOURCE_FILES_PAR})

target_include_directories(sequential_lib PUBLIC sequential utils)

target_include_directories(parallel_lib PUBLIC parallel utils)