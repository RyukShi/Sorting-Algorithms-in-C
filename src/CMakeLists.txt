cmake_minimum_required(VERSION 3.10)

project(SortingAlgorithms C)

# Add flags
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Werror")

# Create libraries
add_library(analytics SHARED analytics.c analytics.h)
add_library(array SHARED array.c array.h)

# Create "SORTING_ALGORITHMS_SOURCES" variable to merge all sorting algorithms
set(SORTING_ALGORITHMS_SOURCES
    bubble-sort.c
    insertion-sort.c
    selection-sort.c
    merge-sort.c
    quick-sort.c
    counting-sort.c
    radix-sort.c
)

# Create "SORTING_ALGORITHMS_HEADERS" variable to merge all header files
set(SORTING_ALGORITHMS_HEADERS
    bubble-sort.h
    insertion-sort.h
    selection-sort.h
    merge-sort.h
    quick-sort.h
    counting-sort.h
    radix-sort.h
)

# Create sorting_algorithms library
add_library(sorting_algorithms SHARED
    ${SORTING_ALGORITHMS_SOURCES}
    ${SORTING_ALGORITHMS_HEADERS}
)
target_link_libraries(sorting_algorithms array)

# Create main executable
add_executable(main main.c)
# Set executable dependencies
target_link_libraries(main analytics array sorting_algorithms)

# Install generate files
install(TARGETS main DESTINATION bin)
install(TARGETS sorting_algorithms DESTINATION lib)
install(TARGETS analytics DESTINATION lib)
install(TARGETS array DESTINATION lib)
install(FILES ${SORTING_ALGORITHMS_HEADERS} DESTINATION include)
