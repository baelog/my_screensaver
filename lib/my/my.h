/*
** EPITECH PROJECT, 2019
** myh
** File description:
** myh
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int  my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab,int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest,char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const * str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest,char const *src, int nb);
int my_strncmp (char const *s1, char const *s2);
char *my_strncpy (char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_evil_str(char *str);
char *my_strcat_one(char *dest, char src);
char *int_to_str(int nb);