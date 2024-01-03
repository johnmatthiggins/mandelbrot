#ifndef MANDELBROT_H
#define MANDELBROT_H

#define PCOUNT 8

struct {
    long x;
    long y;
} typedef Point;

void fill_screen(uint8_t* screen_buffer);
double adjust_dimension(long value, long end, double new_start, double new_end);
void fill_space(long start, long end, uint8_t* screen_buffer);

long get_milliseconds();

#endif
