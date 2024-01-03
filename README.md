# Mandelbrot

## Goals

* Generate a 4k visualization of the Mandelbrot set.
* Make it fast.

## How to Run

You must be on a UNIX-like system to run this program, or use something like Cygwin or WSL on Windows.

Because we use a Python script to render the results, you have to setup a virtual environment as part of the setup.
Here's the process from all the way from setting up the environment to running the generating the image.

```sh
make setup # setup the python environment
make build # build the program
make run   # run the program
```

## Results

Here's a 10,000x10,000 rendering of the Mandelbrot set.

![A fractal resulting from the Mandelbrot set](./mandelbrot_hd.png)

Here's a zoomed in rendering of the fractal.

![Zoomed in rendering of fractal](./mandelbrot.png)
