from visualizer import plot_execution_time, extract_data
from forecasting import extrapolate
from pandas import concat


def main():
    df = extract_data("data_file")

    slowest_algorithms = ["insertion sort", "selection sort", "bubble sort",
                          "counting sort"]
    slowest_df = df[df["algorithm_name"].isin(slowest_algorithms)]
    if not slowest_df.empty:
        plot_execution_time(slowest_df, "slowest_algorithms")

        max_slowest = 1500000
        extra_bubble_sort_df = extrapolate(
            slowest_df, "bubble sort", max_slowest, "quadratic")
        extra_insertion_sort_df = extrapolate(
            slowest_df, "insertion sort", max_slowest, "quadratic")
        extra_selection_sort_df = extrapolate(
            slowest_df, "selection sort", max_slowest, "quadratic")
        extra_counting_sort_df = extrapolate(
            slowest_df, "counting sort", max_slowest)
        extra_slowest_df = concat(
            [extra_bubble_sort_df, extra_insertion_sort_df,
             extra_selection_sort_df, extra_counting_sort_df], ignore_index=True)
        plot_execution_time(extra_slowest_df, "extra_slowest_algorithms")

    fastest_algorithms = ["merge sort", "quick sort", "radix sort",
                          "heap sort"]
    fastest_df = df[df["algorithm_name"].isin(fastest_algorithms)]
    if not fastest_df.empty:
        plot_execution_time(fastest_df, "fastest_algorithms")

        max_fastest = 5000000
        extra_merge_sort_df = extrapolate(
            fastest_df, "merge sort", max_fastest)
        extra_quick_sort_df = extrapolate(
            fastest_df, "quick sort", max_fastest)
        extra_radix_sort_df = extrapolate(
            fastest_df, "radix sort", max_fastest)
        extra_heap_sort_df = extrapolate(
            fastest_df, "heap sort", max_fastest)
        extra_fastest_df = concat(
            [extra_merge_sort_df, extra_quick_sort_df,
             extra_radix_sort_df, extra_heap_sort_df], ignore_index=True)
        plot_execution_time(extra_fastest_df, "extra_fastest_algorithms")


if __name__ == '__main__':
    main()
