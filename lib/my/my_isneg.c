/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_isneg.c
*/

#include "my.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_isneg(int n)
{
    if (n < 0)
        write(1, "N", 1);
    else
        write(1, "P", 1);
    return 0;
}
