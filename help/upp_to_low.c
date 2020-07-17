/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** upp_to_low
*/

#include "my.h"

int	upp_to_low(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    else
        return (c);
}
