#pragma once
#include <math.h>
#include "vec3.h"

typedef struct {
    float x, y, z, w;
} vec4;

static inline vec4 vec4_create(float x, float y, float z, float w) { return (vec4){x, y, z, w}; }

static inline vec4 vec4_from_vec3(vec3 v, float w) { return (vec4){v.x, v.y, v.z, w}; }

static inline vec4 vec4_add(vec4 a, vec4 b) { return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
static inline vec4 vec4_subtract(vec4 a, vec4 b) { return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
static inline vec4 vec4_scale(vec4 v, float scalar) { return (vec4){v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar}; }

static inline float vec4_dot(vec4 a, vec4 b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w); }
static inline float vec4_length(vec4 v) { return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

static inline vec4 vec4_normalized(vec4 v) {
    float len = vec4_length(v);
    return (len > 0.0f) ? vec4_scale(v, 1.0f / len) : (vec4){0.0f, 0.0f, 0.0f, 0.0f};
}