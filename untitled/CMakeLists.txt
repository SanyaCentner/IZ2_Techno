cmake_minimum_required(VERSION 3.20)

project(untitled C CXX)

#set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 17)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(GCC_COVERAGE_COMPILE_FLAGS "--coverage")
add_compile_options("--coverage")
add_link_options("--coverage")

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
        gtest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(gtest)

enable_testing()


add_subdirectory(project)
add_subdirectory(tests)
add_subdirectory(lib)
