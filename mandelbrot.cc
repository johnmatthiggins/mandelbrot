#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <cstdio>

#include <iostream>

#include "mandelbrot.h"

#define HEIGHT (3000)
#define WIDTH (3000)

const uint8_t PALETTE[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

int main() {
    uint8_t* screen_buffer = (uint8_t*)malloc(HEIGHT * WIDTH * sizeof(uint8_t));
    fill_screen(screen_buffer);

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
    for (long i = 0; i < WIDTH; i++) {
        for (long j = 0; j < HEIGHT; j++) {
            const double x0 = ((double)(i - WIDTH)) * (1 / (double)WIDTH);
            const double y0 = ((double)(j - HEIGHT)) * (1 / (double)HEIGHT);
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

            const size_t index = (size_t)i * WIDTH + j;

            screen_buffer[index] = color;
        }
    }
}
