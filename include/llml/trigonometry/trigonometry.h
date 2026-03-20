#pragma once

/*
 * converts an angle from degrees to radians by multiplying by pi divided by 180.
 */
static inline float llml_deg_to_rad(float degrees) {
    return degrees * (M_PI / 180.0f);
}

/*
 * converts an angle from radians to degrees by multiplying by 180 divided by pi.
 */
static inline float llml_rad_to_deg(float radians) {
    return radians * (180.0f / M_PI);
}

/*
 * calculates the length of the hypotenuse of a right triangle from the two shorter sides
 * using the pythagorean theorem as the square root of a squared plus b squared.
 */
static inline float llml_hypotenuse(float a, float b) {
    return sqrtf((a * a) + (b * b));
}

/*
 * calculates an unknown side length of a triangle using the law of sines.
 * given side b and its opposite angle beta in degrees, and the angle alpha in degrees
 * opposite to the unknown side, returns the length of that unknown side.
 */
static inline float llml_law_sines_side(float b, float alpha_degrees, float beta_degrees) {
    return (b * sinf(llml_deg_to_rad(alpha_degrees))) / sinf(llml_deg_to_rad(beta_degrees));
}

/*
 * calculates the side of a triangle opposite to a given angle using the law of cosines.
 * given two sides b and c and their included angle alpha in degrees, returns the length
 * of the opposite side using the formula square root of b squared plus c squared minus
 * 2 times b times c times the cosine of alpha.
 */
static inline float llml_law_cosines_side(float b, float c, float alpha_degrees) {
    float alpha_radians = llml_deg_to_rad(alpha_degrees);
    return sqrtf((b * b) + (c * c) - 2.0f * b * c * cosf(alpha_radians));
}

/*
 * calculates the angle in degrees from the origin to the point defined by x and y
 * using the two argument arctangent function.
 */
static inline float llml_angle_to_point(float y, float x) {
    return llml_rad_to_deg(atan2f(y, x));
}
