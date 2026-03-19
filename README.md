# llml - low level math library

this is a simple header only math library written in c23
I built it because I wanted a fast lightweight way to handle math for vulkan and 3d graphics
without the bloat of massive frameworks it is designed to be easy to read and easy to drop into any project.

---

### what it provides

the library is split into small logical parts so you only use what you need 

![](https://img.shields.io/badge/vectors-linear--algebra-blue)
high performance 2d 3d and 4d vectors along with 4x4 matrices for transformations like rotation scaling and perspective projection

![](https://img.shields.io/badge/physics-collision-red)
basic logic for checking if things hit each other including aabb boxes spheres and ray sphere intersections

![](https://img.shields.io/badge/random-xorshift32-orange)
a fast xorshift32 generator that is way better for games than the standard c rand function

![](https://img.shields.io/badge/geometry-trig-green)
helpers for area and volume of shapes plus essential trigonometry like the law of sines and cosines

![](https://img.shields.io/badge/utility-easing-yellow)
extra stuff like easing functions smoothstep bounce for animations and hex to float color conversion

### why use it

![](https://img.shields.io/badge/type-header--only-lightgrey)
there are no complex build steps just copy the files and include the main header
  
![](https://img.shields.io/badge/standard-c23-brightgreen)
it uses c23 standards and is optimized with static inline functions to keep things fast

![](https://img.shields.io/badge/platform-cross--platform-blueviolet)
works on windows linux or anything with a standard c compiler


### integration

to use it in your own code just include the umbrella header

#include "llml.h"

to build the provided tests you can use the included makefile

Bash:
make

windows powershell:
mingw32-make
