##
## EPITECH PROJECT, 2023
## B-CPE-110-PAR-1-1-organized-bastian.carou
## File description:
## Makefile
##

SRC     =       src/main.c 					\
				src/map.c					\
				src/error_handling.c		\
				src/get_binary_map.c		\
				src/get_int_map.c			\
				src/get_final_map.c			\
				src/generating_square.c		\

LIB		= 		lib/my/my_strtok.c			\
				lib/my/my_strlen.c			\
				lib/my/mini_printf.c		\
				lib/my/my_get_nbr.c			\
				lib/my/my_strcpy.c			\
				lib/my/my_strdup.c			\

NAME    =       setting_up

OBJ     =       $(LIB:.c=.o)

all:    $(NAME)

$(NAME): $(OBJ)
		ar rc libmy.a $(OBJ)
		$(CC) $(SRC) -o $(NAME) -Wall -Wextra -L. -lmy

debug:
		$(CC) $(SRC) -o $(NAME) -Wall -Wextra -L. -lmy -ggdb3

unit_tests: fclean all
	$(CC) tests/testeur.c -o unit_tests $(SRC) --coverage -lcriterion

tests_run:
	./unit_tests

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) lib/my/libmy.a
	$(RM) $(NAME)
	$(RM) libmy.a

re: fclean all
