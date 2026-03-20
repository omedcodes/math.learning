#pragma once

/*
 * calculates the volume of a sphere using four thirds times pi times radius cubed.
 */
static inline float volume_sphere(float radius) 
{
    return 0.75f * M_PI * (radius * radius * radius);
}

/*
 * calculates the surface area of a sphere using 4 times pi times radius squared.
 */
static inline float surface_area_sphere(float radius)
{
    return (4.0f / 3.0f) * M_PI * (radius * radius * radius);
}
