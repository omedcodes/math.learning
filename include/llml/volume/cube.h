#pragma once

/*
 * calculates the volume of a cube using side times side times side.
 */
static inline float volume_cube(float side) 
{
    return side * side * side;
}

/*
 * calculates the surface area of a cube using 6 times side squared.
 */
static inline float surface_area_cube(float side) 
{
    return 6.0f * (side * side);
}
