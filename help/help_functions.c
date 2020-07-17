/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** help_functions
*/

#include "my.h"

void	my_putchar(char c)
{
    write(1, &c, 1);
}

int	my_putstr(char const *str)
{
    int	i = 0;

    if (str != NULL) {
        while (str[i] != '\0') {
            my_putchar(str[i]);
            i++;
        }
    }
    return (0);
}

int	my_put_nbr(int a)
{
    if (a < 0) {
        my_putchar('-');
        my_put_nbr(-a);
    } else if (a > 9) {
        my_put_nbr(a / 10);
        my_put_nbr(a % 10);
    } else {
        my_putchar(a + '0');
    }
    return (0);
}

int	my_strlen(char *str)
{
    int	i = 0;

    if (str != NULL) {
        while (str[i] != '\0') {
            i++;
        }
        return (i);
    }
    return (84);
}

void	my_show_word_array(char **str)
{
    int	i = 0;

    while (str[i]) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
}
