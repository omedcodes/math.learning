#pragma once
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} vec3;

/*
 * creates a new 3d vector with the given x, y, and z components.
 */
static inline vec3 vec3_create(float x, float y, float z)
{
    return (vec3){x, y, z};
}

/*
 * adds two 3d vectors together component wise and returns the result.
 */
static inline vec3 vec3_add(vec3 a, vec3 b)
{
    return (vec3){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z };
}

/*
 * subtracts vector b from vector a component wise and returns the result.
 */
static inline vec3 vec3_subtract(vec3 a, vec3 b) 
{
    return (vec3){ .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z };
}

/*
 * multiplies each component of a 3d vector by a scalar value and returns the result.
 */
static inline vec3 vec3_scale(vec3 v, float scalar) 
{
    return (vec3){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar };
}

/*
 * calculates the magnitude of a 3d vector using the pythagorean theorem
 * as the square root of x squared plus y squared plus z squared.
 */
static inline float vec3_length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/*
 * returns a unit vector pointing in the same direction as the input vector
 * by dividing each component by the vector length.
 * returns a zero vector if the input length is zero to avoid division by zero.
 */
static inline vec3 vec3_normalized(vec3 v) 
{
    float len = vec3_length(v);
    if (len > 0.0f) {
        return vec3_scale(v, 1.0f / len);
    }
    return (vec3){0.0f, 0.0f, 0.0f};
}

/*
 * calculates the dot product of two 3d vectors using the sum of
 * a.x times b.x, a.y times b.y, and a.z times b.z.
 * useful for finding the angle between two vectors or projecting one vector onto another.
 */
static inline float vec3_dot(vec3 a, vec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

/*
 * calculates the cross product of two 3d vectors and returns a new vector
 * that is perpendicular to both input vectors.
 * the resulting vector follows the right hand rule for its direction.
 */
static inline vec3 vec3_cross(vec3 a, vec3 b) 
{
    return (vec3){ .x = a.y * b.z - a.z * b.y, .y = a.z * b.x - a.x * b.z, .z = a.x * b.y - a.y * b.x};
}
