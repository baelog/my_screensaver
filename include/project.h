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
typedef struct rectangle_s rectangle_t;
typedef struct socle_s socle_t;
typedef struct my_clock_s my_clock_t;
typedef struct repere_s repere_t;
typedef struct window_s window_t;
typedef struct text_s text_t;

typedef struct window_s {
    sfRenderWindow* window;
    sfVideoMode mode;
    sfEvent event;
}window_t;

typedef struct project_s {
    window_t *my_window;
    rectangle_t *needle;
    socle_t *socle;
    repere_t *repere;
    my_clock_t *clock;
    text_t *city;
    struct project_s *prev;
    struct project_s *next;
}project_t;


typedef struct rectangle_s {
    sfRectangleShape *hour;
    sfRectangleShape *minute;
    sfRectangleShape *second;
    sfVector2f poshour;
    sfVector2f posminute;
    sfVector2f possecond;
    sfVector2f sizehour;
    sfVector2f sizeminute;
    sfVector2f sizesecond;
}rectangle_t;

typedef struct socle_s {
    sfCircleShape *circle;
    sfCircleShape *inside;
    sfVector2f vectorclock;
    sfVector2f clockinside;
    sfColor colorclock;
}socle_t;

typedef struct repere_s {
    sfCircleShape *twelve;
    sfCircleShape *three;
    sfCircleShape *six;
    sfCircleShape *nine;
    sfVector2f vectortwelve;
    sfVector2f vectorthree;
    sfVector2f vectorsix;
    sfVector2f vectornine;
}repere_t;

typedef struct my_clock_s {
    sfClock *my_clock;
    sfTime time;
    int timehour;
    int timeminute;
    int timesecond;
}my_clock_t;

typedef struct text_s {
    sfVector2f textvector;
    sfText *text;
    sfFont *font;
} text_t;

void my_tree(void);
void my_event(project_t *);
void branch(float, sfVertex, sfVertex, project_t *, float, int);
void my_clock(char **);
window_t *init_window(void);
my_clock_t *init_clock(void);
rectangle_t *init_rectangle(int, int);
socle_t *init_base(int, int);
repere_t *init_repere(int, int);
text_t *init_text(char *, int, int);
my_clock_t *init_clock_add(int, project_t*);
project_t *init_struct_one();
project_t *add_struct(project_t *, int, int, char **);
