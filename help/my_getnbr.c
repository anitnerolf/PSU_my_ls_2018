/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** my_getnbr
*/

#include "my.h"

int	my_getnbr(char const *str)
{
    int	i = 0;
    int	nbr = 0;
    int	y = 1;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            y = -1 * y;
        } else if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10 + str[i] - 48;
        } else
            return (nbr * y);
        i++;
    }
    return (nbr * y);
}
