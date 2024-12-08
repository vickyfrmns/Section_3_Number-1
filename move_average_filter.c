#include <stdio.h>
#include <string.h> // Required for string manipulations such as memset

#define BUFFER_SIZE 24

typedef struct
{
    float buffer[BUFFER_SIZE];
    uint8_t index;
    float sum;
} MovingAverageFilter;

/**
 * This function to implement moving average filter
 * @param filter    parameter to proses data include save and update array indeks
 * @param sample    parameter data from reading a sensor
 *
 */
float MovingAverage_Process(MovingAverageFilter *filter, float sample)
{
    filter->sum -= filter->buffer[filter->index];      // Subtract old value from total amount
    filter->buffer[filter->index] = sample;            // Update new value to buffer
    filter->sum += sample;                             // Sum new value to get a total amount
    filter->index = (filter->index + 1) % BUFFER_SIZE; // Update buffer indeks using circular method
    float filtered_value = filter->sum / BUFFER_SIZE;  // Calculate to get average value
    return filtered_value;
}

int main()
{
    MovingAverageFilter filter;
    memset(&filter, 0, sizeof(filter));

    while (1)
    {
        float sensor_data_dummy = 16.3;
        float update_value = MovingAverage_Process(&filter, sensor_data_dummy);
    }
}