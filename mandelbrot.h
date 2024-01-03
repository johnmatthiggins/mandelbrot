#ifndef MANDELBROT_H
#define MANDELBROT_H

#define PCOUNT 8

#define HEIGHT (10000)
#define WIDTH (10000)


struct {
    long x;
    long y;
} typedef Point;

void fill_screen(uint8_t* screen_buffer);
double adjust_dimension(size_t value, size_t end, double new_start, double new_end);
void fill_space(size_t start, size_t end, uint8_t* screen_buffer);

long get_milliseconds();

#endif
