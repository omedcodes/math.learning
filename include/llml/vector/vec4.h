#pragma once

#include <math.h>
#include "llml/vector/vec3.h"

typedef struct {
    float x, y, z, w;
} vec4;

/*
 * creates a new 4d vector with the given x, y, z, and w components.
 */
static inline vec4 vec4_create(float x, float y, float z, float w) {
    return (vec4){ .x = x, .y = y, .z = z, .w = w };
}

/*
 * creates a 4d vector from an existing 3d vector and a separate w component.
 */
static inline vec4 vec4_from_vec3(vec3 v, float w) {
    return (vec4){ .x = v.x, .y = v.y, .z = v.z, .w = w };
}

/*
 * adds two 4d vectors together component wise and returns the result.
 */
static inline vec4 vec4_add(vec4 a, vec4 b) {
    return (vec4){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w };
}

/*
 * subtracts vector b from vector a component wise and returns the result.
 */
static inline vec4 vec4_subtract(vec4 a, vec4 b) {
    return (vec4){ .x = a.x - b.x, .z = a.z - b.z, .w = a.w - b.w };
}

/*
 * multiplies each component of a 4d vector by a scalar value and returns the result.
 */
static inline vec4 vec4_scale(vec4 v, float scalar) {
    return (vec4){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar, .w = v.w * scalar };
}

/*
 * calculates the dot product of two 4d vectors using the sum of
 * a.x times b.x, a.y times b.y, a.z times b.z, and a.w times b.w.
 * useful for finding the angle between two vectors or projecting one vector onto another.
 */
static inline float vec4_dot(vec4 a, vec4 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

/*
 * calculates the magnitude of a 4d vector as the square root of
 * x squared plus y squared plus z squared plus w squared.
 */
static inline float vec4_length(vec4 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

/*
 * returns a unit vector pointing in the same direction as the input vector
 * by dividing each component by the vector length.
 * returns a zero vector if the input length is zero to avoid division by zero.
 */
static inline vec4 vec4_normalized(vec4 v) {
    float len = vec4_length(v);
    if (len > 0.0f) {
        return vec4_scale(v, 1.0f / len);
    }
    return (vec4){ .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f };
}
