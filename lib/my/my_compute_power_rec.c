/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_power_rec.c
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    long int result = 1;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    result = nb * (my_compute_power_rec(nb, p - 1));
    if (result > 2147483647 || result < -2147483648)
        return (0);
    return (result);
}
