/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** my_screensaver.c
*/

#include "include/project.h"
#include "include/my.h"
#include <math.h>

void branch(float change, sfVertex *my_line, project_t *var, float angle)
{
    sfVertex line[3];
    line[0].position.x = my_line[0].position.x;
    line[0].position.y = my_line[0].position.y;
    line[0].color = my_line[0].color;
    line[1].position.x = my_line[1].position.x;
    line[1].position.y = my_line[1].position.y;
    line[1].color = my_line[1].color;
    float result = sqrt(pow(abs(line[1].position.x - line[0].position.x), 2) + pow((line[1].position.y - line[0].position.y), 2)) * change;
    float x30 = line[0].position.x;
    float y30 = line[0].position.y;
    if (result > 4) {
        float x2 = line[0].position.x + cos(3.1415 * (float)2 - angle) * result;
        float y2 = line[0].position.y + sin(3.1415 * (float)2 - angle) * result;
        line[1].position.x = line[0].position.x;
        line[1].position.y = line[0].position.y;
        line[0].position.x = x2;
        line[0].position.y = y2;
        sfRenderWindow_drawPrimitives(var->window, line, 255, sfLines, NULL);
        sfRenderWindow_display(var->window);
        branch(change, line, var, angle + (3.1415 / 4));
        float x3 = x30 + cos(3.1415 * (float)2 + (angle - 3.1415 / 4 * 2)) * result;
        float y3 = y30 - sin(3.1415 * (float)2 + (angle + 3.1415 / 4 * 6)) * result;
        line[0].position.x = x3;
        line[0].position.y = y3;
        sfRenderWindow_drawPrimitives(var->window, line, 255, sfLines, NULL);
        sfRenderWindow_display(var->window);
        //while (1);
        branch(change, line, var, angle + (3.1415 / 2 * 3));
    }
}