#include <stdio.h>
#include "llml.h"

int main() 
{
    /* circle testing */
    float circle_area = area_circle(3.55f);
    float circumference = circumference_circle(3.55f);
    printf("circle area: %f\ncircle circumference: %f\n", circle_area, circumference);

    /* square testing */
    float square_area = area_square(9.1f);
    float sqaure_perimeter = perimeter_square(9.1f);
    printf("square area: %f\nsquare perimeter: %f\n", square_area, sqaure_perimeter);

    /* rectangle testing */
    float rectangle_area = area_rectangle(3.4f, 5.2f);
    float rectangle_perimeter = perimeter_rectangle(3.4f, 5.2f);
    printf("rectangle area: %f\nrectangle perimeter: %f\n", rectangle_area, rectangle_perimeter);

    /* triangle testing */
    float triangle_area = area_triangle(4.5f, 5.5f);
    float triangle_perimeter = perimeter_triangle(2.2f, 3.3f, 4.4f);
    printf("triangle area: %f\ntriangle perimeter: %f\n", triangle_area, triangle_perimeter);

    /* cube testing */
    float cube_volume = volume_cube(7.4f);
    float cube_surface_area = surface_area_cube(7.4f);
    printf("cube volume: %f\ncube_surface_area: %f\n", cube_volume, cube_surface_area);
    return 0;
}