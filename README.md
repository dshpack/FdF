# FdF
FdF is a 3D Wireframe Viewer (macOS is only supported).
A simple 3D height-map render. You can rotate, move, and zoom models, color is defined by relative height in the map or by specialized keys.

![Image alt](https://github.com/dshpack/FdF/blob/master/images/Screen%20Shot%202020-03-05%20at%208.44.54%20PM.png)

### Features
+ Simple file format definition (array of space-separated integers)
+ 3D rotations with the mouse
+ Camera controls (zoom, translate)
+ Pretty color gradients!
+ Double-buffered
+ Line clipping

To get started with a project, you need to choose which map to open:

`./fdf test_maps/42.fdf`

In the first argument you put a file with a 2D array, of the following form:

[]`0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0`

Where the numbers (in the range Max or Min ints) are the heights of the points
