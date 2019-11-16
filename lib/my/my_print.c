/*
** EPITECH PROJECT, 2019
** print
** File description:
** print
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb *(-1);
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb +'0');
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb == -2147483648)
        write(1, "2147483648", 11);
}

void my_putstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        write(1, &str[i], 1);
}
