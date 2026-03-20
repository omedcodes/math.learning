#pragma once

#include <math.h>
#include <stdbool.h>

typedef struct
{
    float x1;
    float x2;
    int solutions;
} quadratic_result;

/*
 * solves a quadratic equation of the form a times x squared plus b times x plus c equals zero
 * using the quadratic formula. returns a struct containing up to two solutions and the solution count.
 * the discriminant b squared minus 4ac determines whether there are 0, 1, or 2 real solutions.
 */
static inline quadratic_result quadratic_formula(float a, float b, float c) {
    quadratic_result res = {0};
    float discriminant = (b * b) - (4.0f * a * c);
    if (discriminant < 0) {
        res.solutions = 0;
    } else if (discriminant == 0) {
        res.x1 = -b / (2.0f * a);
        res.solutions = 1;
    } else {
        float sqrt_d = sqrtf(discriminant);
        res.x1 = (-b + sqrt_d) / (2.0f * a);
        res.x2 = (-b - sqrt_d) / (2.0f * a);
        res.solutions = 2;
    }
    return res;
}

/*
 * linearly interpolates between values a and b by the factor t.
 * when t is 0 the result is a, when t is 1 the result is b.
 * values of t outside 0 to 1 will extrapolate beyond the range.
 */
static inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

/*
 * clamps a value to within a given min and max range inclusive.
 * returns min if the value is below min and max if the value is above max.
 */
static inline float clamp(float value, float min, float max) {
    if(value < min)
        return min;
    if(value > max)
        return max;
    return value;
}

/*
 * remaps a value from one numeric range to another.
 * a value at in_min maps to out_min and a value at in_max maps to out_max.
 * values outside the input range will be extrapolated linearly.
 */
static inline float map(float value, float in_min, float in_max, float out_min, float out_max) {
    return out_min + (out_max - out_min) * ((value - in_min) / (in_max - in_min));
}
