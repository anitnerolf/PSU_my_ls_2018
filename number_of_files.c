/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** number_of_files
*/

#include "my.h"

int	take_with_dir(DIR *d, char *str)
{
    struct	dirent	*dir;
    int	i = 0;

    d = opendir(str);
    check_dir(d, str);
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            i++;
        }
    }
    return (i);
    closedir(d);
}

int	size(char *av)
{
    DIR	*d = opendir(av);
    struct	dirent	*dir;
    int	size = 0;

    check_dir(d, av);
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            size = size + block_size(dir->d_name);
        }
    }
    return (size);
    closedir(d);
}

char	**print_file_name_dir(DIR *d, char *str)
{
    char	**s = NULL;
    struct	dirent	*dir;
    int	i = 0;
    int	k = 0;
    int	z = take_with_dir(d, str);

    check_dir(d, str);
    s = malloc(sizeof(*s) * (z + 1));
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            s[i] = malloc(sizeof(*s[i]) * (my_strlen(dir->d_name)) + 1);
            s[i] = my_strdup(dir->d_name);
            i++;
        }
    }
    s[i] = NULL;
    return (s);
    free(s);
}

void	print_total_param(char *av)
{
    my_putstr("total ");
    my_put_nbr(size(av) / 2);
    my_putchar('\n');
}

void	check_dir(DIR *d, char *str)
{
    if (!d) {
        my_putstr("ls: cannot access '");
        my_putstr(str);
        my_putstr("': No such file or directory\n");
        exit (84);
    }
}
