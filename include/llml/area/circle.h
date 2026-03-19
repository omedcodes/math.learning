#pragma once

/*
 * Calculates the total area of a circle.
 * Formula: PI * radius^2
 */
static inline float area_circle(float radius) 
{
    return M_PI * (radius * radius);
}

/*
 * Calculates the perimeter (circumference) of a circle.
 * Formula: 2 * PI * radius
 */
static inline float circumference_circle(float radius) 
{
    return 2.0 * M_PI * radius;
}