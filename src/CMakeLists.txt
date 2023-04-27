cmake_minimum_required(VERSION 3.0)

project(SortingAlgorithms C)
# Add flags
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Werror")
# Create libraries
add_library(analytics SHARED analytics.c analytics.h)
add_library(array SHARED array.c array.h)
add_library(sorting-algorithms SHARED sorting-algorithms.c sorting-algorithms.h)
# Create main executable
add_executable(main main.c)
# Set executable dependencies
target_link_libraries(main analytics array sorting-algorithms)
