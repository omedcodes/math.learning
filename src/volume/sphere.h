#pragma once

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

static inline float volume_sphere(float radius) 
{
    return 0.75f * M_PI * (radius * radius * radius);
}

static inline float surface_area_sphere(float radius)
{
    return 4 * M_PI * (radius * radius);
}