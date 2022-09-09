# fractol

This is a fractal renderer made in C as a school project.
The code compiles on Linux.
You might need to install the `libbsd-dev` and `libxext-dev` packages so that the code compiles.
This is because we had to use the minilibX for this project, a graphical library made by the school.
`make` then `./fractol` to display the manual.

Arrow keys are used to move around the fractal. Plus and minus are used to increase or decrease precision. The mouse wheel is used to zoom and dezoom.

Beware the higher the precision the slower the program, be patient. Also since double have a finite precision if you zoom enough the image will inevitably become pixellated.

This program can render the Mandelbrot set and the Julia set. Look at the wikipedia page of the Julia set for example values of c.
