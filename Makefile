##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## Makefile
##

SRC	=	main.c				\
		hard_link_space.c		\
		./help/my_getnbr.c		\
		./help/my_strdup.c		\
		my_second_stat.c		\
		my_stat.c			\
		./help/my_strcat.c		\
		number_of_files.c		\
		number_of_files_param.c		\
		print_all.c			\
		second_user_name_align.c	\
		size_digits.c			\
		size_digits_param.c		\
		user_name_align.c		\
		print_file.c			\
		flag_check.c			\
		./help/help_functions.c		\
		second_flag_check.c		\
		./help/my_strcmp.c		\
		./help/upp_to_low.c		\
		link_digits_param.c		\
		param_user_name_align.c		\
		param_name.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -g3 -ggdb -I ./include

NAME	=	my_ls

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all
