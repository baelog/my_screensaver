/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "include/my.h"
#include "include/project.h"
#include "math.h"

int my_pixel(void);

void my_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->my_window->window, &project->my_window->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(project->my_window->window);
        if (project->my_window->event.type == sfEvtClosed)
            sfRenderWindow_close(project->my_window->window);
    }
}

int main(int ac, char **av)
{
    if ((ac % 2))
        return 84;
    //if (my_strlen(av[1]) != 1)
    //    return 84;
    if (my_getnbr(av[1]) == 1) {
        my_tree();
        return 0;
    }
    if (my_getnbr(av[1]) == 2) {
        av += 2;
        my_clock(av);
        return 0;
    }
    if (my_getnbr(av[1]) == 3) {
        my_pixel();
        return 0;
    }
    if (my_strcmp(av[1], "-h")) {
        write(1, "USAGE:\n\
\t./my_screensaver \"option\"\n\
\tescape to leaev full screen", 63);
        write(1, "OPTIONS:\n\
\t./my_screensaver <option>\n\
SPECIFIC USAGE:\n\
\tdate +\"%X\" | ./my_screensaver 2 <city1> <time zone1> <city2> <time zone2>\n\
\tExemple:\n\
\t\tdate +\"%X\" | ./my_screensaver 2 London -1\n", 182);
        return 0;
    }
    if (my_strcmp(av[1], "-d")) {
        write(1, "1: tree fractal\n", 17);
        write(1, "2: clock\n", 10);
        write(1, "3: circle\n", 11);
        return 0;
    }
    return 84;
}