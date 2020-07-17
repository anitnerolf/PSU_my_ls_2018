/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stddef.h>

typedef	struct	double_str
{
    int i;
    int j;
    int k;
}	double_t;

typedef	struct	sort
{
    char	a;
    char	b;
}	sort_t;

typedef	struct	directory
{
    DIR	*d;
    struct	dirent	*dir;
    char	*str;
} directory_t;

void	check_for_file(int ac, char **av, DIR *d);
void	file_check(char **av);
void	to_check(char **av, DIR *d);
void	print_error(DIR *d, char **av);
void	check_fourth(int ac, char **av);
void	to_check_fourth(int ac, char **av);
void	link_print_some_spaces_param(char *av, char *str);
void	print_spaces_p(char *av, char *str);
void	second_print_spaces_p(char *av, char *str);
int	upp_to_low(char c);
void	check_r(int ac, char **av);
void	check_into_r(int ac, char **av);
int	print_rotate_files(char *av);
void	check_second_argument(int ac, char **av);
void	check_l_r(int ac, char **av);
void	check_main(int ac, char **av);
char	**do_rotate(int ac, char **av);
char	**sort_name(int ac, char **av);
int	print_second_files(char *str);
int	my_strcmp(char *str, char *ptr);
void	check_dir(DIR *d, char *str);
char	**take_str(int z, char *av);
int	block_size(char *filepath);
void	print(char *str);
char	**print_file_name_dir(DIR *d, char *str);
char	*my_strcat(char *str, char *ptr);
void	print_all_second(char *av, char *str);
void	print_all(char **av);
void	print_file(char *av);
int	first_print_name_space(char *av);
int	first_print_some_name_spaces(char *av);
int	print_some_name_spaces(char *av);
void	print_some_spaces(char *av);
void	print_some_spaces_param(char *av, char *str);
void	print_some_spaces_link(char *av);
int	all_number_digits(char *av);
int	number_of_digits(char *av);
int	number_of_digits_link(char *av);
int	print_file_name_second(DIR *d, char *av);
int	print_second_list(char *av);
void	print_files(DIR *d);
int	size(char *av);
int	size_param(char *av);
void	file_rights(char *filepath);
void	modification_time(char *filepath);
void	my_putchar(char c);
int	my_putstr(char const *str);
int	case_d(int ac, char **av);
int	print_list(int ac, char **av);
char	**print_file_name(void);
int	size_of_file(char *filepath);
int	number_of_gid(char *filepath);
int	number_of_uid(char *filepath);
char	*user_name(char *filepath);
char	*first_user_name(char *filepath);
char	*second_user_name(char *filepath);
int	number_of_hard_links(char *filepath);
int	my_put_nbr(int a);
int	my_strlen(char *str);
void	my_show_word_array(char **str);
int	take_with_dir(DIR *d, char *av);
int	number_of_digits_param(char *k);
void	print_total_param(char *str);
void	print_second(char *av, char *str);
void	print_total(char *str);
char	*my_strdup(char *str);

#endif /* MY_H_ */
