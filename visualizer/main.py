from visualizer import plot_execution_time, extract_data
from forecasting import extrapolate


def main():
    df = extract_data("data_file")

    slowest_algorithms = [
        "insertion sort",
        "selection sort",
        "bubble sort"
    ]
    slowest_df = df.query("algorithm_name in @slowest_algorithms")
    plot_execution_time(
        slowest_df,
        "slowest_algorithms.html"
    )

    fastest_algorithms = [
        "merge sort",
        "quick sort",
        "radix sort",
    ]
    fastest_df = df.query("algorithm_name in @fastest_algorithms")
    plot_execution_time(
        fastest_df,
        "fastest_algorithms.html"
    )

    extra_bubble_sort_df = extrapolate(df, "bubble sort", "quadratic")
    plot_execution_time(
        extra_bubble_sort_df,
        "extra_bubble_sort"
    )


if __name__ == '__main__':
    main()
