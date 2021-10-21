# OpenGL_Algos

## Install OpenGL (Linux)
For Installation - 
```
sudo apt-get install freeglut3-dev
```
For compilation - 
```
gcc filename.c -lGL -lGLU -lglut
OR
g++ filename.cpp -lGL -lGLU -lglut
```

## Midpoint Line Drawing Algorithm

Question - Implement the Midpoint Line Drawing Algorithm (using only integer operations) to draw a line from the point (x0, y0) to (x1, y1), Here x0, x1 can be anywhere in the range (30, 400) and y0, y1 can be anywhere in the range (30, 400). Display your output on a viewport of size 500 with left top corner at (10, 30).

Compile and Run - 
```
g++ Q1.cpp -lGL -lGLU -lglut
./a.out
```
Output -  

![Line](https://github.com/saurabhburewar/Assignments_OpenGL-Algos/blob/main/Results/Line.png)

## Triangle rasterization and supersampling

Question - Implement the bounding box based algorithm to draw a triangle with vertices (x0, y0), (x1, y1), (x2, y2). Here, xi, yi can be anywhere in the range (10, 400). Extend the incremental line drawing (integer operations) to draw a triangle. To reduce the stair-casing effect, implement the supersampling technique. First draw a triangle at the resolution of 2× the resolution of the original window and then apply supersampling.

Compile and Run - 
```
g++ Q2.cpp -lGL -lGLU -lglut
./a.out
```
To run Q2 without Supersampling -
    Comment out Lines: 116-120 and 33-46

Output -  

![Triangle](https://github.com/saurabhburewar/Assignments_OpenGL-Algos/blob/main/Results/Triangle.png)

## Midpoint Circle Drawing Algorithm 

Implement the Midpoint Circle Drawing Algorithm (using only integer operations) to draw an arc of radius 100 pixels centered at (200, 200) and starting from 135◦ to 215◦. The use of 8-way symmetry is strictly prohibited. Traverse along the arc in the counter-clockwise direction. Use the appropriate size of the window and viewport.

Compile and Run - 
```
g++ Q3.cpp -lGL -lGLU -lglut
./a.out
```
Output -  

![Circle](https://github.com/saurabhburewar/Assignments_OpenGL-Algos/blob/main/Results/Circle.png)
