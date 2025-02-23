raytracer
=========
A ray tracing renderer I wrote from scratch using C++

![](https://github.com/wilandrade/raytracer/blob/master/Renders/10-RayTracer.jpg)

Features:
=========
Anti aliasing

![](https://github.com/wilandrade/raytracer/blob/master/Renders/8-With%20Anti-Aliasing%20-%2032%20samples.jpg)

Depth of Field

![](https://github.com/wilandrade/raytracer/blob/master/Renders/9-With%20Depth%20of%20Field.jpg)

Smooth Shadows

![](https://github.com/wilandrade/raytracer/blob/master/Renders/7-FirstSmoothShadows.jpg)

Diffuse Shading

![](https://github.com/wilandrade/raytracer/blob/master/Renders/4-FirstDiffuseRender-Success.jpg)


Additional Features
==================
* Custom Scene Description Language
  - Simple tokenizer/parser
  - Declarative syntax for scene setup
  - Supports camera, lights, materials, and primitives
  - Easy to extend with new object types

* Software Architecture
  - Singleton pattern for global systems
  - Factory pattern for material and primitive creation
  - Separation of concerns between rendering, tracing, and scene management
  

Building the Project
-------------------
Create and enter the build directory:
```mkdir build```
```cd build```
Generate build files with CMake:
```cmake ..```
Build the project:
```cmake --build .```
Run the raytracer:
```./raytracer```
This will generate a render.raw file in the build directory.

Viewing the Output
-----------------
The raytracer outputs raw RGB data that needs to be converted for viewing. I created a Python script called raw_visualizer.py in the tools folder in the project root

To view the rendered image make sure you have python3 installed and then run the script:
From the build folder:
```python3 ../tools/raw_visualizer.py```


Requirements
-----------
CMake 3.10 or higher
C++ compiler (gcc, clang, or msvc)
Python 3.x with PIL and numpy packages (only for the raw_visualizer.py script)

