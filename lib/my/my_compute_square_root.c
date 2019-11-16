/*
** EPITECH PROJECT, 2019
** square root
** File description:
** just a return 0
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int number;

    for(number = 0; number * number < nb; ++number);
    if (number * number != nb)
        return (0);
    return (number);
}
