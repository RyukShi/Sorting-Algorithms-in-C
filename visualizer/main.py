from visualizer import plot_execution_time, extract_data


def main():
    merge_quick_radix_df = extract_data('merge_quick_radix')
    plot_execution_time(
        merge_quick_radix_df,
        'merge_quick_radix.html',
        True
    )


if __name__ == '__main__':
    main()
