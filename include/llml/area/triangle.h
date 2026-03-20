#pragma once

/*
 * calculates the area of a triangle using half times base times height.
 */
static inline float area_triangle(float base, float height) 
{
    return 0.5f * (base * height);
}

/*
 * calculates the perimeter of a triangle by summing all three side lengths a, b, and c.
 */
static inline float perimeter_triangle(float a, float b, float c)
{
    return a + b + c;
}
