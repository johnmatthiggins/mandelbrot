#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <cstdio>

#include <iostream>
#include <vector>
#include <thread>

#include "mandelbrot.h"

#define HEIGHT (long)(10000)
#define WIDTH (long)(10000)

const uint8_t PALETTE[11] = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200 };

int main() {
    uint8_t* screen_buffer = (uint8_t*)malloc(HEIGHT * WIDTH * sizeof(uint8_t));

    long start = get_milliseconds();
    fill_screen(screen_buffer);
    long end = get_milliseconds();

    printf("%ld milliseconds\n", end - start);

    // create buffer
    FILE* fptr = fopen("output", "wb");

    for (size_t i = 0; i < WIDTH; ++i) {
        for (size_t j = 0; j < HEIGHT; ++j) {
            const size_t index = i * WIDTH + j;
            fputc(screen_buffer[index], fptr);
        }
    }

    return 0;
}

void fill_screen(uint8_t* screen_buffer) {
    std::vector<std::thread> threads;
    const long step = (HEIGHT * WIDTH) / PCOUNT;
    long next_index = 0;

    for (long i = 0; i < PCOUNT; i++) {
        printf("STARTING THREAD %ld\n", i);
        long start_index = next_index;
        long end_index = start_index + step;

        if (i < (HEIGHT * WIDTH) % PCOUNT) {
            end_index++;
        }

        next_index = end_index;

        std::thread p(fill_space, start_index, end_index, screen_buffer);
        threads.push_back(std::move(p));
    }
    printf("Kicked off threads...\n");

    for (long i = 0; i < threads.size(); i++) {
        threads.at(i).join();
    }
}

double adjust_dimension(long value, long end, double new_start, double new_end) {
    const double diff = new_end - new_start;
    const double increments = diff / (double)end;

    return new_start + ((double)value) * increments;
}

void fill_space(long start, long end, uint8_t* screen_buffer) {
    for (long i = start; i < end; i++) {
        const long x_index = i / WIDTH;
        const long y_index = i % WIDTH;

        const double x0 = adjust_dimension(y_index, WIDTH, -2, 0.5);
        const double y0 = adjust_dimension(x_index, HEIGHT, -1.75, 1.75);
        double x = 0;
        double y = 0;

        long iteration = 0;
        const long max_iteration = 1000;

        while (x * x + y * y <= 4 && iteration < max_iteration) {
            const double xtemp = x * x - y * y + x0;
            y = 2 * x * y + y0;
            x = xtemp;

            iteration++;
        }

        const uint8_t color = PALETTE[iteration];
        const size_t index = (size_t)x_index * WIDTH + y_index;

        screen_buffer[index] = color;
    }
}

long get_milliseconds() {
    auto time = std::chrono::system_clock::now();
    auto since_epoch = time.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);
    long now = millis.count();

    return now;
}
