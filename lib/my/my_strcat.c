/*
** EPITECH PROJECT, 2019
** strcat
** File description:
** strcat
*/

#include "my.h"
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int i;
    int a;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest[i]; ++i)
        str[i] = dest[i];
    for (a = 0; src[a]; ++a, ++i)
        str[i] = src[a];
    str[i] = '\0';
    return (str);
}

char *my_strcat_one(char *dest, char src)
{
    int i;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + 2));

    for (i = 0; dest[i]; ++i)
        str[i] = dest[i];
    str[i] = src;
    str[i + 1] = '\0';
    return (str);
}
