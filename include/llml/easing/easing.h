#pragma once
#include <math.h>

/*
 * smoothly interpolates t through a cubic hermite curve clamped between 0.0 and 1.0.
 * the output starts and ends with zero slope, producing a gradual ease in and ease out effect.
 * uses the formula t squared times 3 minus 2 times t.
 */
static inline float smoothstep(float t) {
    t = clamp(t, 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

/*
 * applies a quadratic ease in curve to t, accelerating from zero velocity.
 * uses the formula t times t.
 */
static inline float ease_in_quad(float t) {
    return t * t;
}

/*
 * applies a quadratic ease out curve to t, decelerating to zero velocity.
 * uses the formula 1 minus the square of 1 minus t.
 */
static inline float ease_out_quad(float t) {
    return 1.0f - (1.0f - t) * (1.0f - t);
}

/*
 * applies a bounce ease out curve to t, simulating the motion of an object
 * bouncing to a stop at the end of the animation.
 * the output always ends at exactly 1.0.
 */
static inline float ease_out_bounce(float t) {
    const float n1 = 7.5625f;
    const float d1 = 2.75f;

    if (t < 1.0f / d1) {
        return n1 * t * t;
    } else if (t < 2.0f / d1) {
        t -= 1.5f / d1;
        return n1 * t * t + 0.75f;
    } else if (t < 2.5f / d1) {
        t -= 2.25f / d1;
        return n1 * t * t + 0.9375f;
    } else {
        t -= 2.625f / d1;
        return n1 * t * t + 0.984375f;
    }
}
