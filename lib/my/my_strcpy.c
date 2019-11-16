/*
** EPITECH PROJECT, 2019
** strcopy
** File description:
** copy
*/

#include "my.h"

char *my_strcpy(char const *src)
{
    int i;
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (i = 0; src[i]; ++i)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
