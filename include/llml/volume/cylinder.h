#pragma once

/*
 * calculates the volume of a cylinder using pi times radius squared times height.
 */
static inline float volume_cylinder(float radius, float height)
{
    return M_PI * (radius * radius) * height;
}

/*
 * calculates the total surface area of a cylinder including both circular caps and the lateral surface.
 * uses the formula 2 times pi times radius times the sum of radius plus height.
 */
static inline float surface_area_cylinder(float radius, float height)
{
    return 2.0f * M_PI * radius * (radius + height);
}
