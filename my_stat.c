/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_stat
*/

#include "my.h"

int	block_size(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_blocks;
    return (file);
}

int	number_of_gid(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_gid;
    return (file);
}

char	*first_user_name(char *filepath)
{
    int	x = number_of_uid(filepath);
    char	*s = NULL;
    struct	passwd	*p;

    p = getpwuid(x);
    s = p->pw_name;
    return (s);
}

int	number_of_uid(char *filepath)
{
    int	file = 0;
    struct	stat	st;

    stat(filepath, &st);
    file = st.st_uid;
    return (file);
}

char	*second_user_name(char *filepath)
{
    int	x = number_of_gid(filepath);
    char	*s = NULL;
    struct	group	*p;

    p = getgrgid(x);
    s = p->gr_name;
    return (s);
}
