/*
** EPITECH PROJECT, 2019
** CPool_Part2
** File description:
** project.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct project_s progect_t;

typedef struct project_s
{
    sfRenderWindow* window;
    sfVideoMode mode;
    sfEvent event;
}project_t;

void my_screensaver(void);
void my_event(project_t *);
void branch(float, sfVertex, sfVertex, project_t *, float, int);
