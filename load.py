#!/usr/bin/env python3
import sys

import numpy as np
import plotly.express as px

def main():
    arr = np.zeros((1000, 1000), dtype=np.int32)

    with open(sys.argv[1], 'rb') as f:
        for i in range(1000):
            for j in range(1000):
                byte = f.read(1)
                arr[i, j] = int.from_bytes(byte, "big")
    
    fig = px.imshow(arr)
    fig.show()

if __name__ == '__main__':
    main()
