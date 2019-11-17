/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "include/my.h"
#include "include/project.h"
#include "math.h"

void my_screensaver(void);
void my_event(project_t *);
void branch(float, sfVertex *, project_t *, float, int);

int Randoms(int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return (num);
    }
}

void my_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(project->window);
    }
}

void my_screensaver(void)
{
    /*int i1 = random_number(1,255);
    int i2 = random_number(1,255);
    int i3 = random_number(1,255);*/
    sfColor color = sfColor_fromRGB((rand() % (255 - 0 + 1)) + 0, (rand() % (255 - 0 + 1)), (rand() % (255 - 0 + 1)) + 0);
    project_t project;
    sfClock *clock;
    int var = 100;
    float len = (float)200;
    float height = (float)860;
    sfVertex line[3];
    line[0].position.x = (float)960;
    line[0].position.y = height - len;
    line[0].color = color;
    line[1].position.x = (float)960;
    line[1].position.y = height;
    line[1].color = color;
    sfVector2f pos = {958, height};
    sfVector2f vector = {4, len};
    int a = 0;
    int b = 0;
    sfVideoMode mode = {1920, 1080, 32};
    project.window = sfRenderWindow_create(mode, "MY_SCREENSAVER", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(project.window, 60);
    while (sfRenderWindow_isOpen(project.window)) {
        my_event(&project);
        sfRenderWindow_clear(project.window, sfBlack);
        sfRenderWindow_display(project.window);
        sfRenderWindow_drawPrimitives(project.window, line, 255, sfLines, NULL);
        sfRenderWindow_display(project.window);
        //clock = sfClock_create();
        //while (clock < 1000);
        //sfClock_destroy(clock);

        branch(0.6, line, &project, 3.1415 / 4 * 3, 0);
        color = sfColor_fromRGB((rand() % (255 - 0 + 1)) + 0, (rand() % (255 - 0 + 1)), (rand() % (255 - 0 + 1)) + 0);
        line[0].position.x = 960;
        line[0].position.y = height - len;
        line[0].color = color;
        line[1].position.x = 960;
        line[1].position.y = height;
        line[1].color = color;
    }
    sfRenderWindow_destroy(project.window);
}

int main(void)
{
    my_screensaver();
}