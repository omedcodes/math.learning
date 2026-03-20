#pragma once

/*
 * calculates the area of a rectangle using side a times side b.
 */
static inline float area_rectangle(float a, float b) 
{
    return a * b;
}

/*
 * calculates the perimeter of a rectangle using 2 times the product of a and b.
 */
static inline float perimeter_rectangle(float a, float b) 
{
    return 2.0f * (a * b);
}
