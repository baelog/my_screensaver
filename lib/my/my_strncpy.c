/*
** EPITECH PROJECT, 2019
** c_pool
** File description:
** my_strncpy.c
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i != n; ++i)
        dest[i] = src[i];
    if (n > my_strlen(src))
        dest[i] = '\0';
    return dest;
}
