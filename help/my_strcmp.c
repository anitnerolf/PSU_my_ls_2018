/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_strcmp
*/

#include "my.h"

int	my_strcmp(char *str, char *ptr)
{
    int	i = 0;
    int	k = 0;

    for (i = 0; str[i] != '\0' && (str[i] == ptr[i]); i++);
    k = str[i] - ptr[i];
    return (k);
}
