/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_strdup
*/

#include "my.h"

char	*my_strdup(char *src)
{
    int	i = 0;
    char	*str = malloc(sizeof(char) * (my_strlen(src) + 1000));

    if (src != NULL) {
        while (src[i] != '\0') {
            str[i] = src[i];
            i++;
        }
        str[i] = '\0';
        return (str);
        free (str);
    } else
        return (NULL);
}
