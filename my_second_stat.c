/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_second_stat
*/

#include "my.h"

void	first_check_file(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_mode;
    if (S_ISDIR(file))
        my_putstr("d");
    else if (S_ISLNK(file))
        my_putstr("l");
    else
        my_putstr("s");
}

void	modification_time(char *filepath)
{
    int	file = 0;
    char	*str = NULL;
    struct	stat	st;
    int	i = 4;
    int	z = 0;

    stat(filepath, &st);
    str = ctime(&st.st_mtime);
    z = my_strlen(str) - 9;
    while (i < z) {
        my_putchar(str[i]);
        i++;
    }
}

void	second_check_file(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_mode;
    if (S_ISBLK(file))
        my_putstr("b");
    else
        my_putstr("c");
}

void	check_file(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_mode;
    if (S_ISDIR(file) || S_ISLNK(file) || S_ISSOCK(file))
        first_check_file(filepath);
    else if (S_ISBLK(file) || S_ISCHR(file))
        second_check_file(filepath);
    else
        my_putstr("-");
}

void	file_rights(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_mode;
    check_file(filepath);
    my_putstr((file & S_IRUSR) ? "r" : "-");
    my_putstr((file & S_IWUSR) ? "w" : "-");
    my_putstr((file & S_IXUSR) ? "x" : "-");
    my_putstr((file & S_IRGRP) ? "r" : "-");
    my_putstr((file & S_IWGRP) ? "w" : "-");
    my_putstr((file & S_IXGRP) ? "x" : "-");
    my_putstr((file & S_IROTH) ? "r" : "-");
    my_putstr((file & S_IWOTH) ? "w" : "-");
    my_putstr((file & S_IXOTH) ? "x" : "-");
}
