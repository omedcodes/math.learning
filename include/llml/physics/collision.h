#pragma once

#include <stdbool.h>
#include "llml/vector/vec2.h"
#include "llml/vector/vec3.h"

/*
 * tests whether a 2d point lies within or on the boundary of an axis aligned bounding box.
 * the box is defined by a min corner and a max corner.
 */
static inline bool col_point_in_aabb2d(vec2 point, vec2 min, vec2 max) {
    return (point.x >= min.x && point.x <= max.x) && (point.y >= min.y && point.y <= max.y);
}

/*
 * tests whether two spheres in 3d space are overlapping or touching.
 * uses squared distance comparison to avoid an unnecessary square root operation.
 */
static inline bool col_sphere_vs_sphere(vec3 pos1, float rad1, vec3 pos2, float rad2) {
    vec3 diff = vec3_subtract(pos1, pos2);
    float distance_sq = vec3_dot(diff, diff); 
    float radii_sum = rad1 + rad2;
    return distance_sq <= (radii_sum * radii_sum);
}

/*
 * tests whether a ray intersects a sphere in 3d space.
 * the ray is defined by an origin point and a normalized direction vector.
 * returns false immediately if the sphere center is behind the ray origin.
 */
static inline bool col_ray_vs_sphere(vec3 ray_origin, vec3 ray_dir, vec3 sphere_center, float sphere_rad) {
    vec3 l = vec3_subtract(sphere_center, ray_origin);
    float tca = vec3_dot(l, ray_dir);
    if (tca < 0) return false;
    float d2 = vec3_dot(l, l) - tca * tca;
    return d2 <= (sphere_rad * sphere_rad);
}
