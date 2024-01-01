#!/usr/bin/env python3
from itertools import islice
import plotly.express as px
import numpy as np

SCALE = 0.00001

def main():
    c = complex_matrix(-2, 0.5, -1.5, 1.5, pixel_density=1000)
    members = get_members(c, num_iterations=20)

    fig = px.scatter(x=members.real, y=members.imag)
    fig.show()

def generate_screen():
    # create a 1000x1000 screen...
    screen = np.zeros((1000, 1000))

    for i in range(screen.shape[0]):
        for j in range(screen.shape[1]):
            adjusted_i = i - (1000 / 2)
            adjusted_j = j - (1000 / 2)
            screen[i, j] = generate_point(adjusted_i * SCALE, adjusted_j * SCALE)

    return screen

def complex_matrix(xmin, xmax, ymin, ymax, pixel_density):
    re = np.linspace(xmin, xmax, int((xmax - xmin) * pixel_density))
    im = np.linspace(ymin, ymax, int((ymax - ymin) * pixel_density))

    return re[np.newaxis, :] + im[:, np.newaxis] * 1j


def sequence(c, z=0):
    while True:
        yield z
        z = z ** 2 + c

def get_members(c, num_iterations):
    mask = is_stable(c, num_iterations)
    return c[mask]

def is_stable(c, num_iterations):
    z = 0
    for _ in range(num_iterations):
        z = z ** 2 + c
    return abs(z) <= 2

if __name__ == '__main__':
    main()
