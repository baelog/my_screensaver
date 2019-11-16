/*
** EPITECH PROJECT, 2019
** CPool_Part2
** File description:
** int_to_str.c
*/

#include "my.h"

char *int_to_str(int nb)
{
    int nb_cpy = nb;
    int i;
    char *nb_str;

    for (i = 0; nb_cpy /= 10; ++i);
    nb_str = malloc(sizeof(char) * (i + 4));
    for (i = 0; nb; ++i) {
        nb_str[i] = nb % 10 + 48;
        nb /= 10;
    }
    nb_str[i] = '\0';
    return (my_revstr(nb_str));
}