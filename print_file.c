/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** print_file
*/

#include "my.h"

void	print_file(char *av)
{
    file_rights(av);
    my_putchar(' ');
    my_put_nbr(number_of_hard_links(av));
    my_putchar(' ');
    my_putstr(first_user_name(av));
    my_putchar(' ');
    my_putstr(second_user_name(av));
    my_putchar(' ');
    my_put_nbr(size_of_file(av));
    my_putchar(' ');
    modification_time(av);
    my_putchar(' ');
    my_putstr(av);
    my_putchar('\n');
}

void	print_error(DIR *d, char **av)
{
    if (errno != ENOTDIR) {
        my_putstr("ls: cannot access '");
        my_putstr(av[1]);
        my_putstr("': No such file or directory\n");
        exit (84);
    } else {
        my_putstr(av[1]);
        my_putchar('\n');
    }
}

void	check_r_param(char *str)
{
    DIR	*d = opendir(str);
    int	z = take_with_dir(d, str);
    char **s = do_rotate(z, print_file_name_dir(d, str));

    my_show_word_array(s);
    closedir(d);
}

void	check_for_file(int ac, char **av, DIR *d)
{
    if (av[2][0] == '-' && av[2][1] == 'r') {
        check_l_r(ac, av);
    } else if (errno != ENOTDIR) {
        my_putstr("ls: cannot access '");
        my_putstr(av[2]);
        my_putstr("': No such file or directory\n");
        exit (84);
    } else {
        if (av[1][0] == '-' && av[1][1] == 'r' && errno == ENOTDIR) {
            my_show_word_array(av + 2);
        } else
            print_file(av[2]);
    }
}

void	file_check(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'l' && av[2]) {
        print_total(av[2]);
        print_second_files(av[2]);
    } else {
        check_r_param(av[2]);
    }
}
