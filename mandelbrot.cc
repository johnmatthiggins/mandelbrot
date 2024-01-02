#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <cstdio>

#include <iostream>

/* #include <opencv2/core.hpp> */
/* #include <opencv2/highgui.hpp> */

#include "mandelbrot.h"

#define LENGTH (10000)

const uint8_t PALETTE[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

int main() {
    uint8_t* screen_buffer = (uint8_t*)malloc(LENGTH * LENGTH * sizeof(uint8_t));
    fill_screen(screen_buffer);

    // create buffer
    FILE* fptr = fopen("output", "wb");

    for (size_t i = 0; i < LENGTH; ++i) {
        for (size_t j = 0; j < LENGTH; ++j) {
            const size_t index = i + j * LENGTH;
            fputc(screen_buffer[index], fptr);
        }
    }

    return 0;
}

void fill_screen(uint8_t* screen_buffer) {
    for (long i = 0; i < LENGTH; i++) {
        for (long j = 0; j < LENGTH; j++) {
            const double x0 = ((double)(i - LENGTH)) * (1 / (double)LENGTH);
            const double y0 = ((double)(j - LENGTH)) * (1 / (double)LENGTH);
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
            printf("%lu\n", color);

            const size_t index = (size_t)i * LENGTH + j;
            printf("index = %d\n", index);
            screen_buffer[index] = color;
        }
    }
}
