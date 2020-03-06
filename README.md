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

#### How to start project
To get started with a project, you need to choose which map to open:

`./fdf test_maps/42.fdf`

In the first argument you put a file with a 2D array, of the following form:

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Where the numbers (in the range Max or Min ints) are the heights of the points.

If desired, you can specify the color of each of the points in the following format:

```
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```
![Image alt](https://github.com/dshpack/FdF/blob/master/images/Screen%20Shot%202020-03-05%20at%208.39.56%20PM.png)
Where you need to put color after the height: 
`15,0xFF0000`

The project works only with the correct maps. This means that the file must specify heights in the minimum-maximum ints, the color should be specified in hexadecimal number (the letters can be upper or lower case) after ``` ,0x ``` and you must specify at least 2x2 map size.

You can also specify a window size as a second argument in the range of 450 to 2560 widths and 200 to 1400 height pixels. Otherwise, the screen size will be set by default, where the width is 1920 and the height is 1080 pixels.
```
"-w500 -h500" 
```

#### Menu
For convenience, the program has a drop-down menu, which will be called by the hotkey `"m"`
Here you will see a list of the full functionality of the program, and all needed hotkeys.
![Image alt](https://github.com/dshpack/FdF/blob/master/images/Screen%20Shot%202020-03-05%20at%208.36.54%20PM.png)
![Image alt](https://github.com/dshpack/FdF/blob/master/images/Screen%20Shot%202020-03-05%20at%208.37.07%20PM.png)

#### Waymark
It would like to say separately for such functionality as a calling Waymark. This feature is added as additional location information about your map in three-dimensional space шin X, Y, Z -axis.
![Image alt](https://github.com/dshpack/FdF/blob/master/images/Screen%20Shot%202020-03-05%20at%208.34.24%20PM.png)
![Image alt](https://github.com/dshpack/FdF/blob/master/images/Screen%20Shot%202020-03-05%20at%208.35.42%20PM.png)
