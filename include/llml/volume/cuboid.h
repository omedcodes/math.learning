#pragma once

/*
 * calculates the volume of a cuboid using the product of its three side lengths a times b times c.
 */
static inline float volume_cuboid(float a, float b, float c) 
{
    return a * b * c;
}

/*
 * calculates the surface area of a cuboid using 2 times the sum of a times b, b times c, and a times c.
 */
static inline float surface_area_cuboid(float a, float b, float c) 
{
    return 2.0f * (a * b + b * c + a * c);
}
