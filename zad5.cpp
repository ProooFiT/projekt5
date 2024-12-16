#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <chrono>
#include <mutex>

// Mutex for thread-safe addition to the result
std::mutex result_mutex;

// Function to calculate part of the integral
double calculate_partial_integral(double start, double end, unsigned long long steps) {
    double sum = 0.0;
    double step_size = (end - start) / steps;
    for (unsigned long long i = 0; i < steps; ++i) {
        double x = start + i * step_size + step_size / 2.0;
        sum += 4.0 / (1.0 + x * x);
    }
    return sum * step_size;
}

