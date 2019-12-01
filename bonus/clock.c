/*
** EPITECH PROJECT, 2019
** MUL
** File description:
** clock.c
*/

#include "../include/project.h"
#include "../include/my.h"

project_t *add_struct(project_t *project, int x, int y, char **av)
{
    project_t *new = malloc(sizeof(project_t));

    new->clock = init_clock_add(my_getnbr(av[1]), project);
    new->needle = init_rectangle(x, y);
    new->repere = init_repere(x, y);
    new->socle = init_base(x, y);
    new->city = init_text(av[0], x, y);
    sfRectangleShape_setRotation(new->needle->hour, 180 + (360/12) * new->clock->timehour);
    sfRectangleShape_setRotation(new->needle->minute, 180 + (360/60) * new->clock->timeminute);
    sfRectangleShape_setRotation(new->needle->second, 180 + (360/60) * new->clock->timesecond);
    while(project->next)
        project = project->next;
    new->next = NULL;
    new->prev = project;
    project->next = new;


    return (project);
}

project_t *init_struct_one(void)
{
    project_t *project = malloc(sizeof(project_t));

    project->my_window = init_window();
    project->clock = init_clock();
    project->needle = init_rectangle(0, 0);
    project->repere = init_repere(0, 0);
    project->socle = init_base(0, 0);
    project->city = init_text("Paris", 0, 0);
    project->prev = NULL;
    project->next = NULL;
    sfRectangleShape_setRotation(project->needle->hour, 180 + (360/12) * project->clock->timehour);
    sfRectangleShape_setRotation(project->needle->minute, 180 + (360/60) * project->clock->timeminute);
    sfRectangleShape_setRotation(project->needle->second, 180 + (360/60) * project->clock->timesecond);
    return (project);
}

window_t *init_window(void)
{
    window_t *my_window = malloc(sizeof(window_t));
    sfVideoMode mode = {1920, 1080, 32};

    my_window = malloc(sizeof(window_t));
    my_window->window = sfRenderWindow_create(mode, "CLOCK", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(my_window->window, 60);
    return(my_window);
}

text_t *init_text(char *str, int x, int y)
{
    text_t *city = malloc(sizeof(text_t));

    city->textvector.x = 20 + x;
    city->textvector.y = 20 + y;
    city->text = sfText_create();
    city->font = sfFont_createFromFile("bonus/Vogue.ttf");
    sfText_setFont(city->text, city->font);
    sfText_setPosition(city->text, city->textvector);
    sfText_setString(city->text, str);
    return (city);
}

my_clock_t *init_clock_add(int decalage, project_t *project)
{
    my_clock_t *clock = malloc(sizeof(my_clock_t));

    clock->timehour = project->clock->timehour + decalage - 1;
    clock->timeminute = project->clock->timeminute;
    clock->timesecond = project->clock->timesecond;
    return(clock);
}

my_clock_t *init_clock(void)
{
    my_clock_t *clock = malloc(sizeof(my_clock_t));
    char buff[11];
    int rd = read(0, buff, 10);

    buff[rd] = '\0';
    clock->my_clock = sfClock_create();
    clock->timehour = (buff[0] - 48) * 10 + buff[1] - 48;
    clock->timeminute = (buff[3] - 48) * 10 + buff[4] - 48;
    clock->timesecond = (buff[6] - 48) * 10 + buff[7] - 48;
    return(clock);
}

rectangle_t *init_rectangle(int x, int y)
{
    rectangle_t *needle = malloc(sizeof(rectangle_t));

    needle->hour = sfRectangleShape_create();
    needle->minute = sfRectangleShape_create();
    needle->second = sfRectangleShape_create();
    needle->poshour.x = 160 + x;
    needle->poshour.y = 200 + y;
    needle->posminute.x = 160 + x;
    needle->posminute.y = 200 + y;
    needle->possecond.x = 160 + x;
    needle->possecond.y = 200 + y;
    needle->sizehour.x = 5;
    needle->sizehour.y = 60;
    needle->sizeminute.x = 4;
    needle->sizeminute.y = 105;
    needle->sizesecond.x = 2;
    needle->sizesecond.y = 105;
    sfRectangleShape_setFillColor(needle->hour, sfBlack);
    sfRectangleShape_setPosition(needle->hour, needle->poshour);
    sfRectangleShape_setSize(needle->hour, needle->sizehour);
    sfRectangleShape_setFillColor(needle->minute, sfRed);
    sfRectangleShape_setPosition(needle->minute, needle->posminute);
    sfRectangleShape_setSize(needle->minute, needle->sizeminute);
    sfRectangleShape_setFillColor(needle->second, sfBlue);
    sfRectangleShape_setPosition(needle->second, needle->possecond);
    sfRectangleShape_setSize(needle->second, needle->sizesecond);
    return (needle);
}

socle_t *init_base(int x, int y)
{
    socle_t *socle = malloc(sizeof(socle_t));

    socle->circle = sfCircleShape_create();
    socle->inside  = sfCircleShape_create();
    socle->vectorclock.x = 20 + x;
    socle->vectorclock.y = 60 + y;
    socle->clockinside.x = 60 + x;
    socle->clockinside.y = 100 + y;
    socle->colorclock = sfColor_fromRGB(73, 22, 22);
    sfCircleShape_setFillColor(socle->circle, sfWhite);
    sfCircleShape_setFillColor(socle->inside, socle->colorclock);
    sfCircleShape_setRadius(socle->circle, 100);
    sfCircleShape_setRadius(socle->inside, 140);
    sfCircleShape_setPosition(socle->circle, socle->clockinside);
    sfCircleShape_setPosition(socle->inside, socle->vectorclock);
    return (socle);
}

repere_t *init_repere(int x, int y)
{
    repere_t *repere = malloc(sizeof(repere_t));

    repere->twelve = sfCircleShape_create();
    repere->three = sfCircleShape_create();
    repere->six = sfCircleShape_create();
    repere->nine = sfCircleShape_create();
    repere->vectortwelve.x = 145 + x;
    repere->vectortwelve.y = 65 + y;
    repere->vectorthree.x = 25 + x;
    repere->vectorthree.y = 185 + y;
    repere->vectorsix.x = 265 + x;
    repere->vectorsix.y = 185 + y;
    repere->vectornine.x = 145 + x;
    repere->vectornine.y = 305 + y;
    sfCircleShape_setRadius(repere->twelve, 15);
    sfCircleShape_setRadius(repere->three, 15);
    sfCircleShape_setRadius(repere->six, 15);
    sfCircleShape_setRadius(repere->nine, 15);
    sfCircleShape_setPosition(repere->twelve, repere->vectortwelve);
    sfCircleShape_setPosition(repere->three, repere->vectorthree);
    sfCircleShape_setPosition(repere->six, repere->vectorsix);
    sfCircleShape_setPosition(repere->nine, repere->vectornine);
    sfCircleShape_setFillColor(repere->twelve, sfBlue);
    sfCircleShape_setFillColor(repere->three, sfBlue);
    sfCircleShape_setFillColor(repere->six, sfBlue);
    sfCircleShape_setFillColor(repere->nine, sfBlue);
    return (repere);
}

void set_holorge(project_t *project)
{
    project_t *temp;
    project->clock->time = sfClock_getElapsedTime(project->clock->my_clock);
    if (project->clock->time.microseconds / 1000000 >= 1) {
        temp = project;
        while(temp) {
            ++temp->clock->timesecond;
            if (temp->clock->timesecond >= 60) {
                temp->clock->timesecond = 0;
                ++temp->clock->timeminute;
            }
            if (temp->clock->timeminute >= 60) {
                temp->clock->timeminute = 0;
                ++temp->clock->timehour;
            }
            sfRectangleShape_setRotation(temp->needle->hour, 180 + (360 / 12) * temp->clock->timehour);
            sfRectangleShape_setRotation(temp->needle->minute, 180 + (360 / 60) * temp->clock->timeminute);
            sfRectangleShape_setRotation(temp->needle->second, 180 + (360 / 60) * temp->clock->timesecond);
            temp = temp->next;
        }
        sfClock_restart(project->clock->my_clock);
    }
}

void display(project_t *project)
{
    project_t *temp = project;
    while (temp) {
        sfRenderWindow_drawText(project->my_window->window, temp->city->text, NULL);
        sfRenderWindow_drawCircleShape(project->my_window->window, temp->socle->inside, NULL);
        sfRenderWindow_drawCircleShape(project->my_window->window, temp->socle->circle, NULL);
        sfRenderWindow_drawRectangleShape(project->my_window->window, temp->needle->hour, NULL);
        sfRenderWindow_drawRectangleShape(project->my_window->window, temp->needle->minute, NULL);
        sfRenderWindow_drawRectangleShape(project->my_window->window, temp->needle->second, NULL);
        sfRenderWindow_drawCircleShape(project->my_window->window, temp->repere->twelve, NULL);
        sfRenderWindow_drawCircleShape(project->my_window->window, temp->repere->three, NULL);
        sfRenderWindow_drawCircleShape(project->my_window->window, temp->repere->six, NULL);
        sfRenderWindow_drawCircleShape(project->my_window->window, temp->repere->nine, NULL);
        temp = temp->next;
    }
}

void my_destroy(project_t *project)
{
    project_t *temp;
    while (project->next)
        project = project->next;
    while (project->prev) {
        temp = project;
        project = project->prev;
        project->next = NULL;
        sfFont_destroy(temp->city->font);
        sfText_destroy(temp->city->text);
        sfCircleShape_destroy(temp->socle->circle);
        sfCircleShape_destroy(temp->socle->inside);
        sfCircleShape_destroy(temp->repere->nine);
        sfCircleShape_destroy(temp->repere->six);
        sfCircleShape_destroy(temp->repere->three);
        sfCircleShape_destroy(temp->repere->twelve);
        sfRectangleShape_destroy(temp->needle->hour);
        sfRectangleShape_destroy(temp->needle->minute);
        sfRectangleShape_destroy(temp->needle->second);
        free(temp->city);
        free(temp->clock);
        free(temp->needle);
        free(temp->repere);
        free(temp->socle);
        free(temp);
    }
    sfFont_destroy(project->city->font);
    sfText_destroy(project->city->text);
    sfClock_destroy(project->clock->my_clock);
    sfCircleShape_destroy(project->socle->circle);
    sfCircleShape_destroy(project->socle->inside);
    sfCircleShape_destroy(project->repere->nine);
    sfCircleShape_destroy(project->repere->six);
    sfCircleShape_destroy(project->repere->three);
    sfCircleShape_destroy(project->repere->twelve);
    sfRectangleShape_destroy(project->needle->hour);
    sfRectangleShape_destroy(project->needle->minute);
    sfRectangleShape_destroy(project->needle->second);
    sfRenderWindow_destroy(project->my_window->window);
    free(project->my_window);
    free(project->city);
    free(project->clock);
    free(project->needle);
    free(project->repere);
    free(project->socle);
    free(project);
}

void my_clock(char **av)
{
    int x = 400;
    int y = 0;
    project_t *project = init_struct_one();
    while (*av) {
        project = add_struct(project, x, y, av);
        av += 2;
        x += 400;
        if (x == 2000) {
            x = 0;
            y += 350;
        }
        while (project->prev)
            project = project->prev;
    }
    while (sfRenderWindow_isOpen(project->my_window->window)) {
        my_event(project);
        sfRenderWindow_clear(project->my_window->window, sfBlack);
        set_holorge(project);
        display(project);
        sfRenderWindow_display(project->my_window->window);
    }
    my_destroy(project);
}