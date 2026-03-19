#pragma once

#include <stdint.h>
#include "llml/vector/vec3.h"

static uint32_t _rng_state = 10000;

/*
 * Sets the global seed for the Xorshift32 generator.
 * @Note A seed of 0 is not allowed and will be defaulted to 10000.
 */
static inline void _seed(uint32_t seed) 
{
    if (seed == 0) seed = 10000;
   _rng_state = seed; 
}

/*
 * Generates a random 32-bit unsigned integer using the Xorshift algorithm.
 * This is significantly faster than standard rand().
 */
static inline uint32_t _rand_uint32(void) 
{
    uint32_t x = _rng_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    _rng_state = x;
    return x;
}

/*
 * Returns a random floating point number between 0.0 and 1.0.
 */
static inline float _rand_float(void) {
    return (float)_rand_uint32() / (float)UINT32_MAX;
}

/*
 * Generates a random integer within a specific [min, max] range.
 */
static inline int _rand_int_range(int _min, int _max) {
    return _min + (_rand_uint32() % (_max - _min + 1));
}

/*
 * Generates a random float within a specific [min, max] range.
 */
static inline float _rand_float_range(float _min, float _max) {
    return _min + _rand_float() * (_max - _min);
}

/*
 * Generates a random bool within a true or false range.
 */
static inline bool _rand_bool(void) {
    return (_rand_uint32() % 2) == 0;
}

static inline vec3 _rand_vec3_range(float _min, float _max) {
    return (vec3) {
      _rand_float_range(_min, _max),
      _rand_float_range(_min, _max),
      _rand_float_range(_min, _max)
  };
}

static inline vec3 _rand_vec3_direction(void) {
    vec3 v = _rand_vec3_range(-1.0f, 1.0f);
    return vec3_normalized(v);
}
