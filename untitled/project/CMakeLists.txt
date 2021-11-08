include_directories(include)

set(PROJECT_SOURCE_FILES src/main.c)

add_executable(project ${PROJECT_SOURCE_FILES})

set_target_properties(project
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/project/)
target_link_libraries(project sequential_lib parallel_lib)