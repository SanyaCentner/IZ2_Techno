cmake_minimum_required(VERSION 3.20)

set(PROJECT_SOURCE_FILES)

add_executable(tests test.cpp ${PROJECT_SOURCE_FILES})
set_target_properties(tests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/tests/)
target_link_libraries(tests gtest ${GTEST_LIBRARIES} pthread)
target_link_libraries(tests sequential_lib parallel_lib)