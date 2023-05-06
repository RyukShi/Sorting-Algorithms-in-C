import os
import plotly.express as px
from pandas import DataFrame


def extract_data(file_name: str):
    data = []
    path_file = os.path.join(os.getcwd(), 'build', file_name)
    with open(path_file, 'r') as file:
        for line in file.readlines():
            values = line.strip().split(',')
            time_taken = float(values[0])
            algorithm_name = values[1]
            array_size = int(values[2])
            data.append({
                'time_taken': time_taken,
                'algorithm_name': algorithm_name,
                'array_size': array_size
            })
    return data


def plot_execution_time(data: list, create_html: bool = False):
    fig = px.line(
        DataFrame(data),
        x='array_size', y='time_taken',
        color='algorithm_name',
        labels=dict(array_size='Array size', time_taken='Time taken (seconds)')
    )
    fig.update_layout(xaxis_type="log")
    if create_html:
        fig.write_html("output.html")
        print('output.html file created successfully!')
    else:
        fig.show()
