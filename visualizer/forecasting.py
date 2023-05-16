from scipy import signal, interpolate
from pandas import DataFrame
from numpy import linspace

def extrapolate(
        df: DataFrame,
        algorithm: str,
        method: str = "linear",
        window_length: int = 7,
        polyorder: int = 3):

    filtered_df = df[df["algorithm_name"] == algorithm]

    # Savitzky-Golay filter
    y_smoothed = signal.savgol_filter(
        filtered_df["time_taken"], window_length, polyorder)

    f = interpolate.interp1d(
        filtered_df["array_size"],
        y_smoothed,
        kind=method,
        fill_value="extrapolate")

    x_extrapolated = linspace(
        filtered_df["array_size"].min(),
        filtered_df["array_size"].max() * 4, 1000)

    y_extrapolated = f(x_extrapolated)

    extrapolated_df = DataFrame(
        {"array_size": x_extrapolated, "time_taken": y_extrapolated})
    extrapolated_df["algorithm_name"] = algorithm

    return extrapolated_df
