/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** user_name_align
*/

#include "my.h"

int	max_length_p(char *av, char *str)
{
    int	y = 0;
    int	max = 0;
    DIR	*d = opendir(str);
    char	*k = NULL;
    int	i = 0;
    int	z = take_with_dir(d, str);
    char **f = sort_name(z, print_file_name_dir(d, str));
    char **p = take_str(z, str);

    while (i < z) {
        k = my_strcat(p[i], f[i]);
        y = my_strlen(first_user_name(k));
        if (y > max) {
            max = y;
        }
        i++;
    }
    return (max);
    closedir(d);
}

int	first_print_name_space_p(char *av, char *str)
{
    int	z = 0;
    int	a = 0;
    int	f = 0;

    z = my_strlen(first_user_name(av));
    a = max_length_p(av, str);
    f = a - z;
    return (f);
}

void	print_spaces_p(char *av, char *str)
{
    int	i = 0;
    int	j = 0;

    i = first_print_name_space_p(av, str);
    for (j = 0; j <= i; j++) {
        my_putchar(' ');
    }
}
