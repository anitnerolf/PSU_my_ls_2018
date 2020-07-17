/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** size_digits_param
*/

#include "my.h"

int	all_link_number_digits_param(char *av, char *str)
{
    DIR	*d = opendir(str);
    struct	dirent	*dir;
    int	i = 0;
    int	z = take_with_dir(d, str);
    char	**f = sort_name(z, print_file_name_dir(d, str));
    char	**p = take_str(z, str);
    int	b = 0;
    int	max = 0;
    char	*k = NULL;

    while (i < z) {
        k = my_strcat(p[i], f[i]);
        b = number_of_digits_link(k);
        if (b > max)
            max = b;
        i++;
    }
    closedir(d);
    return (max);
}

int	link_print_spaces_param(char *av, char *str)
{
    int	z = 0;
    int	a = 0;
    int	f = 0;

    z = number_of_digits_link(av);
    a = all_link_number_digits_param(av, str);
    f = a - z;
    return (f);
}

void	link_print_some_spaces_param(char *av, char *str)
{
    int	i = 0;
    int	j = 0;

    i = link_print_spaces_param(av, str);
    for (j = 0; j <= i; j++) {
        my_putchar(' ');
    }
}
