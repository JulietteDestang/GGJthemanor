##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC 	= 	src/main.c	\
			src/door.c	\
			src/main_menue.c	\

OBJ 	= 	$(SRC)

NAME 	=	lost

all:	$(NAME)

$(NAME):	$(SRC)
	cd lib/my && make all
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I./include -L lib/my/ -lmy -lm

clean:
	make -C lib/my clean

VAL :
	cd lib/my && make all
	gcc -o $(NAME) $(SRC) -L lib/my/ -lmy $(CPPFLAGS) -g3

fclean:
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
