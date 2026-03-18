#include <stdio.h>
#include "llml.h"

int main() 
{
    _seed(798980);

    printf("--- RNG Integer Test (Dice) ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Roll %d: %d\n", i + 1, _rand_int_range(1, 6));
    }

    printf("\n--- RNG Float Test (0.0 to 1.0) ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Float %d: %f\n", i, _rand_float());
    }

    printf("\n--- 3D Random Vector Test ---\n");
    // lets gen a random dir and check its length
    // if its normalized length should be 1.0f
    vec3 rand_dir = _rand_vec3_direction();
    printf("Random dir: [%f, %f, %f]\n", rand_dir.x, rand_dir.y, rand_dir.z);
    printf("Dir Length: %f (should be 1.0)\n", vec3_length(rand_dir));
    
    return 0;
}
