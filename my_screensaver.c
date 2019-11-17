/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** my_screensaver.c
*/

#include "include/project.h"
#include "include/my.h"
#include <math.h>

void branch(float change, sfVertex my_point1, sfVertex my_point2, project_t *var, float angle, int a)
{
    sfVertex vertex1;
    sfVertex vertex2;
    sfVertexArray *array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(array, sfLines);
    vertex1.position.x = my_point1.position.x;
    vertex1.position.y = my_point1.position.y;
    vertex1.color = my_point1.color;
    vertex2.position.x = my_point2.position.x;
    vertex2.position.y = my_point2.position.y;
    vertex2.color = my_point2.color;
    float result = sqrt(pow(abs(vertex2.position.x - vertex1.position.x), 2) + pow((vertex2.position.y - vertex1.position.y), 2)) * change;
    float x30 = vertex1.position.x;
    float y30 = vertex1.position.y;
    if (result > 4) {
        if (a)
            angle = angle + (3.1415 / 4);
        float x2 = vertex1.position.x + cos(3.1415 * (float)2 - angle) * result;
        float y2 = vertex1.position.y + sin(3.1415 * (float)2 - angle) * result;
        vertex2.position.x = vertex1.position.x;
        vertex2.position.y = vertex1.position.y;
        vertex1.position.x = x2;
        vertex1.position.y = y2;
        my_event(var);
        sfVertexArray_append(array, vertex1);
        sfVertexArray_append(array, vertex2);
        sfRenderWindow_drawVertexArray(var->window, array, NULL);
        sfRenderWindow_display(var->window);
        branch(change, vertex1, vertex2, var, angle + (3.1415 / 4), 0);
        float x3 = x30 + cos(3.1415 * (float)2 + (angle - 3.1415 / 4 * 2)) * result;
        float y3 = y30 - sin(3.1415 * (float)2 + (angle + 3.1415 / 4 * 6)) * result;
        vertex1.position.x = x3;
        vertex1.position.y = y3;
        my_event(var);
        sfVertexArray_append(array, vertex1);
        sfVertexArray_append(array, vertex2);
        sfRenderWindow_drawVertexArray(var->window, array, NULL);
        sfRenderWindow_display(var->window);
        branch(change, vertex1, vertex2, var, angle - (3.1415 / 2), 1);
    }
}