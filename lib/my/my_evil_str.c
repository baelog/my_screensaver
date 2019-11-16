/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_evil_str.c
*/

#include "my.h"

char *my_evil_str(char *str)
{
    int i = my_strlen(str);
    int ii = -1;
    char temp;

    while (++ii < i--) {
        temp = str[i];
        str[i] = str[ii];
        str[ii] = temp;;
    }
    return (str);
}
