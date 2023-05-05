cmake_minimum_required(VERSION 3.0)

project(SortingAlgorithms C)
# Add flags
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Werror")
# Create libraries
add_library(analytics SHARED analytics.c analytics.h)
add_library(array SHARED array.c array.h)
# Create "SOURCE_FILES" variable to merge all sorting algorithms
set(SOURCE_FILES bubble-sort.c insertion-sort.c selection-sort.c merge-sort.c
    quick-sort.c counting-sort.c radix-sort.c)
add_library(sorting_algorithms SHARED ${SOURCE_FILES} sorting-algorithms.h)
# Create main executable
add_executable(main main.c)
# Set executable dependencies
target_link_libraries(main analytics array sorting_algorithms)
