/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** test.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>

#define LINE_LEN(x, y) (sqrt(pow(x, 2) + pow(y, 2)))

typedef struct framebuffer framebuffer_t;
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    framebuffer->height = height;
    framebuffer->width = width;

    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    framebuffer->pixels[y * x * 4] = color.r; // R?
    framebuffer->pixels[y * x * 4 + 1] = color.g; // G?
    framebuffer->pixels[y * x * 4 + 2] = color.b; // B?
    framebuffer->pixels[y * x * 4 + 3] = color.a; // A?
}

void my_put_pixel_black(framebuffer_t *framebuffer, unsigned int x, unsigned int y)
{
    framebuffer->pixels[y * x * 4] = 0; // R?
    framebuffer->pixels[y * x * 4 + 1] = 0; // G?
    framebuffer->pixels[y * x * 4 + 2] = 0; // B?
    framebuffer->pixels[y * x * 4 + 3] = 255; // A?
}

int my_pixel(void)
{
    int y_min = 0;
    int x_circle = -200;
    int y_circle = rand() % 1080;
    int temp_y_circle;
    int temp_x_circle;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;
    framebuffer_t *framebuffer;
    sfColor color = {rand() % 256, rand() % 256, rand() % 256, 255};
    sfClock *clock= sfClock_create();
    sfTime time;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    framebuffer = framebuffer_create(1920, 1080);

    texture = sfTexture_create(1920, 1080);
    if (!texture)
        return 84;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);
        }
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds / 10000 >= 1) {
            for (int y = 0; y != 1080; ++y) {
                for (int x = 0; x <= 1920; ++x)
                    my_put_pixel_black(framebuffer, x + (1920 * y), 1);
            }
            for (temp_x_circle = x_circle - 50, color.a = 5; color.a != 255; color.a += 50, temp_x_circle += 10) {
                for (int y = 0; y != 1080; ++y) {
                    for (int x = 0; x <= 1920; ++x) {
                        if (((x - temp_x_circle) * (x - temp_x_circle) + (y - y_circle) * (y - y_circle)) <= 50 * 50)
                            my_put_pixel(framebuffer, x + (1920 * y), 1, color);
                        if (((x - temp_x_circle) * (x - temp_x_circle) + (y - y_circle) * (y - y_circle)) <= 20 * 20)
                            my_put_pixel(framebuffer, x + (1920 * y), 1, sfBlack);
                    }
                }
            }
            x_circle += 5;
            sfClock_restart(clock);
        }
        if (x_circle > 1920 + 200) {
            x_circle = -200;
            y_circle = rand() % 1080;
            color.r = rand() % 256;
            color.g = rand() % 256;
            color.b = rand() % 256;
        }
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    framebuffer_destroy(framebuffer);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}