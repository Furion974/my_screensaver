##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compilator
##

SRC     =       src/usage.c	\
		src/main.c	\
		src/pixel.c	\
		src/sky.c	\
		src/circle.c

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -I ./include -g -g3 -W -Wall -Werror -ansi -pedantic

NAME    =       my_screensaver

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-system -lcsfml-window -lm

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all
