/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** user_name_align
*/
#include "my.h"

int	first_max_user_name_length(char *av)
{
    int	k = 0;
    int	max = 0;
    DIR	*d = opendir(".");
    struct	dirent	*dir;

    check_dir(d, ".");
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            k = my_strlen(first_user_name(dir->d_name));
            if (k > max)
                max = k;
        }
    }
    return (max);
    closedir(d);
}

int	first_print_name_space(char *av)
{
    int	z = 0;
    int	a = 0;
    int	f = 0;

    z = my_strlen(first_user_name(av));
    a = first_max_user_name_length(av);
    f = a - z;
    return (f);
}

int	first_print_some_name_spaces(char *av)
{
    int	i = 0;
    int	j = 0;

    i = first_print_name_space(av);
    for (j = 0; j < i; j++) {
        my_putchar(' ');
    }
}
