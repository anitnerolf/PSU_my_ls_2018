/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** flag_check
*/

#include "my.h"

void	check_main(int ac, char **av)
{
    DIR	*d;

    if (ac == 3) {
        d = opendir(av[2]);
        if (!d) {
            check_for_file(ac, av, d);
        } else {
            file_check(av);
        }
        closedir(d);
    } else {
        check_fourth(ac, av);
    }
}

void	check_fourth(int ac, char **av)
{
    DIR *d;

    if (ac == 4) {
        if (av[1][0] == '-' && av[1][1] == 'l' && \
    av[2][0] == '-' && av[2][1] == 'r' && av[3]) {
            to_check(av, d);
        } else
            exit (84);
    } else
        to_check_fourth(ac, av);
}

void	check_twice(int ac, char **av)
{
    DIR	*d = opendir(av[1]);
    int	z = 0;
    char	**f = NULL;

    if (!d) {
        print_error(d, av);
        exit (84);
    } else {
        z = take_with_dir(d, av[1]);
        f = sort_name(z, print_file_name_dir(d, av[1]));
        my_show_word_array(f);
    }
    closedir(d);
}

void	check_l(int ac, char **av)
{
    DIR	*d = opendir(".");
    int	i = 0;
    int	z = take_with_dir(d, ".");
    char **k = sort_name(z, print_file_name_dir(d, "."));

    print_total_param(".");
    while (k[i]) {
        print(k[i]);
        i++;
    }
    closedir(d);
}

void	check_second_argument(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'l') {
        check_l(ac, av);
    } else if (av[1][0] == '-' && av[1][1] == 'r') {
        check_r(ac, av);
    } else {
        check_twice(ac, av);
    }
}
