#pragma once

/*
 * calculates the area of a square using side times side.
 */
static inline float area_square(float side) 
{
    return side * side;
}

/*
 * calculates the perimeter of a square using 4 times the side length.
 */
static inline float perimeter_square(float side) 
{
    return 4.0f * side;
}
