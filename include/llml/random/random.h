#pragma once

#include <stdint.h>
#include "llml/vector/vec3.h"

static uint32_t _rng_state = 10000;

/*
 * sets the global seed for the xorshift32 random number generator.
 * a seed value of zero is not allowed and will be replaced with 10000.
 */
static inline void _seed(uint32_t seed) 
{
    if (seed == 0) seed = 10000;
   _rng_state = seed; 
}

/*
 * generates a random unsigned 32 bit integer using the xorshift algorithm.
 * this is significantly faster than the standard rand function.
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
 * generates a random floating point number in the range 0.0 to 1.0 inclusive.
 */
static inline float _rand_float(void) {
    return (float)_rand_uint32() / (float)UINT32_MAX;
}

/*
 * generates a random integer within the inclusive range from min to max.
 */
static inline int _rand_int_range(int _min, int _max) {
    return _min + (_rand_uint32() % (_max - _min + 1));
}

/*
 * generates a random float within the inclusive range from min to max.
 */
static inline float _rand_float_range(float _min, float _max) {
    return _min + _rand_float() * (_max - _min);
}

/*
 * generates a random boolean value that is either true or false with equal probability.
 */
static inline bool _rand_bool(void) {
    return (_rand_uint32() % 2) == 0;
}

/*
 * generates a vec3 with each component set to a random float within the given min to max range.
 */
static inline vec3 _rand_vec3_range(float _min, float _max) {
    return (vec3) {
      _rand_float_range(_min, _max),
      _rand_float_range(_min, _max),
      _rand_float_range(_min, _max)
  };
}

/*
 * generates a random unit vec3 pointing in a uniformly distributed random direction.
 * the result is normalized so its length is 1.
 */
static inline vec3 _rand_vec3_direction(void) {
    vec3 v = _rand_vec3_range(-1.0f, 1.0f);
    return vec3_normalized(v);
}
