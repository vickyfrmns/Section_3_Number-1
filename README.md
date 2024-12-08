# Moving Average Filter Implementation

This repository contains a simple C program implementing a Moving Average Filter for processing and smoothing sensor data. This implementation is specifically designed for embedded systems with fixed buffer size and utilizes efficient memory handling techniques such as circular indexing.

## Overview

A Moving Average Filter is used to reduce noise in a signal by calculating the average of the most recent data points. This implementation supports:

- Fixed-size buffer (BUFFER_SIZE).
- Efficient circular indexing for memory reuse.
- Lightweight computation suitable for real-time applications in embedded systems.

## How It Works

1. Initialize the filter using memset to set all buffer values index, and sum to 0.

2. For each incoming sensor data:

- Remove the oldest value from the sum.
- Add the new value to the buffer and update the sum.
- Move the buffer index forward using circular indexing.
- Compute the filtered value as the average of the buffer contents.

## Customization

1. Buffer Size: Change `BUFFER_SIZE` to adjust the number of data points considered in the moving average. Larger sizes provide smoother results but slower response to changes.
2. Sensor Data: Replace `sensor_data_dummy` with actual sensor readings in `main`.

## Example Output

If the input data is constant at `16.3`, the filter will gradually stabilize to the same value:

```bash
Input: 16.3, Filtered: 0.68
Input: 16.3, Filtered: 1.36
Input: 16.3, Filtered: 16.3  (after buffer fills)
```

## Applications

This implementation is suitable for:

- Embedded systems requiring noise reduction.
- IoT devices processing sensor data in real-time.
- Smoothing signals in control systems or measurement applications.
