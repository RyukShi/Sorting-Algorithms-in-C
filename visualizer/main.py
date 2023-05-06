from visualizer import plot_execution_time, extract_data

def main():
    data = extract_data('execution_time')
    plot_execution_time(data, True)

if __name__ == '__main__':
    main()
