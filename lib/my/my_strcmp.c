/*
** EPITECH PROJECT, 2019
** strcmp
** File description:
** strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[1] && s2[i]; ++i);
    if (s1[i] != s2[i])
        return 0;
    return 1;
}
