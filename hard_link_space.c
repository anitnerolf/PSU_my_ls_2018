/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** hard_link_space.c
*/

#include "my.h"

int	number_digits_link(char *av)
{
    int	k = 0;
    int	max = 0;
    DIR	*d = opendir(".");
    struct	dirent	*dir;

    if (d == NULL) {
        perror(".");
        return (84);
    }
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            k = number_of_digits_link(dir->d_name);
            if (k > max)
                max = k;
        }
    }
    closedir(d);
    return (max);
}

int	print_spaces_link(char *av)
{
    int	z = 0;
    int	a = 0;
    int	f = 0;

    z = number_of_digits_link(av);
    a = number_digits_link(av);
    f = a - z;
    return (f);
}

void	print_some_spaces_link(char *av)
{
    int	i = 0;
    int	j = 0;

    i = print_spaces_link(av);
    for (j = 0; j <= i; j++) {
        my_putchar(' ');
    }
}

int	number_of_digits_link(char *av)
{
    int	a = number_of_hard_links(av);
    int	i = 0;

    for (i = 0; a != 0; i++) {
        a = a / 10;
    }
    return (i);
}

int	number_of_hard_links(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_nlink;
    return (file);
}
