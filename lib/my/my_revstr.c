/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str) {
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i =my_strlen(str);
    int a = -1;

    while (i)
        cpy[++a] = str[--i];
    cpy[a + 1] = '\0';
    free(str);
    return (cpy);
}