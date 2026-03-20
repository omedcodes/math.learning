#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <llml/llml.h>
#include <windows.h>

#define WIDTH 80
#define HEIGHT 40

vec3 cube_vertices[] = {
    {-1, -1, -1}, { 1, -1, -1}, { 1,  1, -1}, {-1,  1, -1},
    {-1, -1,  1}, { 1, -1,  1}, { 1,  1,  1}, {-1,  1,  1}
};

int cube_edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

void draw_line(char buffer[HEIGHT][WIDTH], int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT)
            buffer[y0][x0] = '#';
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

int main() {
    float angle = 0.0f;
    char buffer[HEIGHT][WIDTH];
    printf("\033[2J\e[?25l");

    while (1) {
        memset(buffer, ' ', sizeof(buffer));

        mat4 model = mat4_identity();
        model = mat4_rotate_y(model, angle);
        model = mat4_rotate_x(model, angle * 0.5f);
        
        vec3 cam_pos = {0, 0, 5};
        mat4 view = mat_look_at(cam_pos, (vec3){0,0,0}, (vec3){0,1,0});
        mat4 projection = mat4_perspective(1.0472f, (float)WIDTH / HEIGHT * 0.5f, 0.1f, 100.0f);
        
        mat4 mvp = mat4_multiply(projection, mat4_multiply(view, model));

        vec2 projected_points[8];
        for (int i = 0; i < 8; i++) {
            vec4 v4 = vec4_from_vec3(cube_vertices[i], 1.0f);
            vec4 clip = mat4_mul_vec4(mvp, v4);
            float w_inv = 1.0f / clip.w;
            float x = clip.x * w_inv;
            float y = clip.y * w_inv;
            
            projected_points[i].x = (x + 1.0f) * 0.5f * (WIDTH - 1);
            projected_points[i].y = (1.0f - (y + 1.0f) * 0.5f) * (HEIGHT - 1);
        }

        for (int i = 0; i < 12; i++) {
            draw_line(buffer, 
                (int)projected_points[cube_edges[i][0]].x, (int)projected_points[cube_edges[i][0]].y,
                (int)projected_points[cube_edges[i][1]].x, (int)projected_points[cube_edges[i][1]].y);
        }

        printf("\033[H"); 
        for (int y = 0; y < HEIGHT; y++) {
            fwrite(buffer[y], 1, WIDTH, stdout);
            putchar('\n');
        }

        angle += 2.0f;
        Sleep(16);
    }
    return 0;
}