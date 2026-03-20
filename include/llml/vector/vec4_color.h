#pragma once
#include <stdint.h>
#include "llml/vector/vec4.h"

/*
 * creates a vec4 color from red, green, and blue byte values in the range 0 to 255.
 * each channel is normalized to the 0.0 to 1.0 range. the alpha component is set to 1.0.
 */
static inline vec4 color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    return (vec4){r / 255.0f, g / 255.0f, b / 255.0f, 1.0f};
}

/*
 * creates a vec4 color from a 24 bit hexadecimal integer in the format 0xRRGGBB.
 * each channel is extracted and normalized to the 0.0 to 1.0 range. the alpha component is set to 1.0.
 */
static inline vec4 color_hex(uint32_t hex) {
    return (vec4){
        ((hex >> 16) & 0xFF) / 255.0f,
        ((hex >> 8) & 0xFF) / 255.0f,
        (hex & 0xFF) / 255.0f,
         1.0f
    };
}
