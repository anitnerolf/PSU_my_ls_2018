/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** number_of_files_param
*/

#include "my.h"

void	print_total(char *av)
{
    my_putstr("total ");
    my_put_nbr(size_param(av) / 2);
    my_putchar('\n');
}

int	size_param(char *str)
{
    DIR	*d = opendir(str);
    struct	dirent	*dir;
    int	i = 0;
    int	z = take_with_dir(d, str);
    char **f = sort_name(z, print_file_name_dir(d, str));
    char **p = take_str(z, str);
    int	b = 0;
    char *k = NULL;

    check_dir(d, str);
    while (i < z) {
        k = my_strcat(p[i], f[i]);
        b = b + block_size(k);
        i++;
    }
    return (b);
    closedir(d);
}

sort_t	*check_for_sort(char *str, char *ptr)
{
    int	i = 0;
    sort_t	*s = malloc(sizeof(sort_t));

    while (upp_to_low(str[i]) == upp_to_low(ptr[i]))
        i++;
    s->a = str[i];
    s->b = ptr[i];
    s->a = upp_to_low(s->a);
    s->b = upp_to_low(s->b);
    return (s);
    free (s);
}

char	**sort_name(int n, char **ptr)
{
    char	*str = NULL;
    int	i = 0;
    int	j = 0;
    sort_t	*s = malloc(sizeof(sort_t));

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            s = check_for_sort(ptr[i], ptr[j]);
            if (s->a > s->b) {
                str = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = str;
            }
        }
    }
    return (ptr);
    free (s);
}

char	**do_rotate(int n, char **ptr)
{
    char	*str = NULL;
    int	i = 0;
    int	j = 0;
    sort_t	*s = malloc(sizeof(sort_t));

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            s = check_for_sort(ptr[i], ptr[j]);
            if (s->a < s->b) {
                str = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = str;
            }
        }
    }
    return (ptr);
    free (s);
}
