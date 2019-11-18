/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "include/my.h"
#include "include/project.h"
#include "math.h"

void my_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(project->window);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (my_strlen(av[1]) != 1)
        return 84;
    if (my_getnbr(av[1]) == 1) {
        my_tree();
        return 0;
    }
    return 84;
}