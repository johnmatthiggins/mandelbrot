#!/usr/bin/env python3
import cv2
import sys

import numpy as np
import plotly.express as px

def main():
    arr = np.zeros((10000, 10000), dtype=np.int32)

    with open(sys.argv[1], 'rb') as f:
        for i in range(arr.shape[0]):
            for j in range(arr.shape[1]):
                byte = f.read(1)
                arr[i, j] = int.from_bytes(byte, "big")
    print('done reading data from file')
    
    # fig = px.imshow(arr)
    # fig.show()

    cv2.imwrite('mandelbrot.png', arr)

if __name__ == '__main__':
    main()
