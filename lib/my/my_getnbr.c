/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr.c
*/

#include "my.h"

int  my_getnbr(char const *str)
{
    int i = -1;
    int neg = 1;
    long int number = 0;

    if (str == NULL)
        return 0;
    while (str[++i] != '\0' && number == 0) {
        if (str[i] == '-')
            neg *= -1;
        while (str[i] >= '0' && str[i] <= '9') {
            number = 10 * number + (str[i] - 48);
            ++i;
        }
    }
    return (number * neg);
}
