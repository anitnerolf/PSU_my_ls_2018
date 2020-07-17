/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** second_flag_check
*/

#include "my.h"

void	to_check_fourth(int ac, char **av)
{
    char **k = do_rotate((ac - 3), av + 3);
    int j = 0;

    while (k[j] != NULL) {
        print_file(k[j]);
        j++;
    }
}

void	to_check(char **av, DIR *d)
{
    d = opendir(av[3]);
    if (!d) {
        if (errno != ENOTDIR) {
            my_putstr("ls: cannot access '");
            my_putstr(av[3]);
            my_putstr("': No such file or directory\n");
            exit (84);
        } else {
            print_file(av[3]);
        }
    } else {
        print_total(av[3]);
        print_rotate_files(av[3]);
    }
    closedir(d);
}

void	check_l_r(int ac, char **av)
{
    DIR	*d = opendir(".");
    int	i = 0;
    int	z = take_with_dir(d, ".");
    char **k = do_rotate(z, print_file_name_dir(d, "."));

    check_dir(d, ".");
    print_total_param(".");
    while (k[i]) {
        print(k[i]);
        i++;
    }
    closedir(d);
}

void	check_r(int ac, char **av)
{
    DIR	*d = opendir(".");
    int	z = take_with_dir(d, ".");
    char **s = do_rotate(z, print_file_name_dir(d, "."));

    check_dir(d, ".");
    my_show_word_array(s);
    closedir(d);
}
