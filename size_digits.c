/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** size_digits
*/

#include "my.h"

int	size_of_file(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_size;
    return (file);
}

int	all_number_digits(char *av)
{
    int	k = 0;
    int	max = 0;
    DIR	*d = opendir(".");
    struct	dirent	*dir;

    check_dir(d, ".");
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            k = number_of_digits(dir->d_name);
            if (k > max)
                max = k;
        }
    }
    return (max);
    closedir(d);
}

int	print_spaces(char *av)
{
    int	z = 0;
    int	a = 0;
    int	f = 0;

    z = number_of_digits(av);
    a = all_number_digits(av);
    f = a - z;
    return (f);
}

void	print_some_spaces(char *av)
{
    int	i = 0;
    int	j = 0;

    i = print_spaces(av);
    for (j = 0; j <= i; j++) {
        my_putchar(' ');
    }
}

int	number_of_digits(char *av)
{
    int	a = size_of_file(av);
    int	i = 0;

    if (a == 0)
        return (i + 1);
    for (i = 0; a != 0; i++) {
        a = a / 10;
    }
    return (i);
}
