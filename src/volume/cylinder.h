#pragma once

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

static inline float volume_cylinder(float radius, float height)
{
    return M_PI * (radius * radius) * height;
}

static inline float surface_area_cylinder(float radius, float height)
{
    return 2 * M_PI * radius * (radius + height);
}
