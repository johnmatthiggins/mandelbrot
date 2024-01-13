#!/usr/bin/env python3
import cv2
import sys

import numpy as np
import plotly.express as px

def main():
    arr = np.zeros((10000, 10000), dtype=np.uint8)

    with open(sys.argv[1], 'rb') as f:
        for i in range(arr.shape[0]):
            for j in range(arr.shape[1]):
                byte = f.read(1)
                arr[i, j] = int.from_bytes(byte, "big")

    blur = cv2.GaussianBlur(arr, (5,5), 0)

    filename = 'mandelbrot_hd.jpg'
    print('Writing to %s...' % filename)
    cv2.imwrite(filename, arr)

if __name__ == '__main__':
    main()
