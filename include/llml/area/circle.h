#pragma once

/*
 * calculates the area of a circle using pi times radius squared.
 */
static inline float area_circle(float radius) 
{
    return M_PI * (radius * radius);
}

/*
 * calculates the circumference of a circle using 2 times pi times radius.
 */
static inline float circumference_circle(float radius) 
{
    return 2.0f * M_PI * radius;
}
