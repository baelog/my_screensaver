/*
** EPITECH PROJECT, 2019
** strncat
** File description:
** strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int a;

    for (i = 0; dest[i]; ++i);
    for (a = 0; src[a] && a != nb; ++a, ++i)
        dest[i] = src[a];
    dest[i] = '\0';
    return (dest);
}
