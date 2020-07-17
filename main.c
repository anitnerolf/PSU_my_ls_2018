/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** main
*/

#include "my.h"

int	do_first(int ac, char **av)
{
    DIR	*d = opendir(".");
    int z = take_with_dir(d, ".");
    char **s = sort_name(z, print_file_name_dir(d, "."));

    my_show_word_array(s);
    closedir(d);
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 1) {
        do_first(ac, av);
    } else if (ac == 2) {
         check_second_argument(ac, av);
    } else {
        check_main(ac, av);
    }
    return (0);
}
