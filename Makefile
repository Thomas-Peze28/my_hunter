##
## EPITECH PROJECT, 2024
## makefile pong seb
## File description:
## makfile
##

SRC	=	main.c	\
		play.c	\
		init.c	\
		init_game.c	\
		window.c	\

NAME	=	my_hunter

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -L./lib/my -lmy -Wall -Wextra -Werror -l csfml-graphics \
		-l csfml-system -l csfml-window -l csfml-audio

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all fclean clean re
