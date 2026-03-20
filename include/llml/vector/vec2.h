#pragma once

#include <math.h>

typedef struct {
    float x;
    float y;
} vec2;

/*
 * creates a new 2d vector with the given x and y components.
 */
static inline vec2 vec2_create(float x, float y) {
    return (vec2){ .x = x, .y = y };
}

/*
 * adds two 2d vectors together component wise and returns the result.
 */
static inline vec2 vec2_add(vec2 a, vec2 b) {
    return (vec2){ .x = a.x + b.x, .y = a.y + b.y };
}

/*
 * subtracts vector b from vector a component wise and returns the result.
 */
static inline vec2 vec2_subtract(vec2 a, vec2 b) {
    return (vec2){ .x = a.x - b.x, .y = a.y - b.y };
}

/*
 * multiplies each component of a 2d vector by a scalar value and returns the result.
 */
static inline vec2 vec2_scale(vec2 v, float scalar) {
    return (vec2){ .x = v.x * scalar, .y = v.y * scalar };
}

/*
 * calculates the dot product of two 2d vectors using the sum of a.x times b.x and a.y times b.y.
 * useful for finding the angle between two vectors or projecting one vector onto another.
 */
static inline float vec2_dot(vec2 a, vec2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

/*
 * calculates the magnitude of a 2d vector using the pythagorean theorem
 * as the square root of x squared plus y squared.
 */
static inline float vec2_length(vec2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

/*
 * returns a unit vector pointing in the same direction as the input vector
 * by dividing each component by the vector length.
 * returns a zero vector if the input length is zero to avoid division by zero.
 */
static inline vec2 vec2_normalized(vec2 v) {
    float len = vec2_length(v);
    if (len > 0.0f) {
        return vec2_scale(v, 1.0f / len);
    }
    return (vec2){ .x = 0.0f, .y = 0.0f };
}
