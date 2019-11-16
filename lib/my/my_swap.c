/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_swap.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
