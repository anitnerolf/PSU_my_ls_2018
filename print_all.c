/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** print_all
*/

#include "my.h"

int	print_rotate_files(char *av)
{
    DIR	*d = opendir(av);
    int	i = 0;
    int	z = take_with_dir(d, av);
    char **f = do_rotate(z, print_file_name_dir(d, av));
    char **p = take_str(z, av);
    char *k = NULL;

    check_dir(d, av);
    while (i < z) {
        k = my_strcat(p[i], f[i]);
        print_second(k, av);
        my_putstr(f[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
    closedir(d);
}

int	print_second_files(char *av)
{
    DIR	*d = opendir(av);
    int	i = 0;
    int	z = take_with_dir(d, av);
    char **f = sort_name(z, print_file_name_dir(d, av));
    char **p = take_str(z, av);
    char *k = NULL;

    check_dir(d, av);
    while (i < z) {
        k = my_strcat(p[i], f[i]);
        print_second(k, av);
        my_putstr(f[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
    closedir(d);
}

char	**take_str(int z, char *av)
{
    int	i = 0;
    char	**str = malloc(sizeof(char *) * (z + 1));

    while (i < z) {
        str[i] = malloc(sizeof(char) * my_strlen(av) + 1);
        str[i] = my_strcat(my_strdup(av), "/");
        i++;
    }
    str[i] = NULL;
    return (str);
    free(str);
}

void	print_second(char *av, char *str)
{
    file_rights(av);
    link_print_some_spaces_param(av, str);
    my_put_nbr(number_of_hard_links(av));
    print_spaces_p(av, str);
    my_putstr(first_user_name(av));
    second_print_spaces_p(av, str);
    my_putstr(second_user_name(av));
    print_some_name_spaces(av);
    print_some_spaces_param(av, str);
    my_put_nbr(size_of_file(av));
    my_putchar(' ');
    modification_time(av);
    my_putchar(' ');
}

void	print(char *av)
{
    file_rights(av);
    print_some_spaces_link(av);
    my_put_nbr(number_of_hard_links(av));
    my_putchar(' ');
    my_putstr(first_user_name(av));
    my_putchar(' ');
    first_print_some_name_spaces(av);
    my_putstr(second_user_name(av));
    print_some_name_spaces(av);
    print_some_spaces(av);
    my_put_nbr(size_of_file(av));
    my_putchar(' ');
    modification_time(av);
    my_putchar(' ');
    my_putstr(av);
    my_putchar('\n');
}
