##
## Makefile for  in /home/berger_t//nibbler-2015-leurqu_m/Game/GameSnake
## 
## Made by thierry berger
## Login   <berger_t@epitech.net>
## 
## Started on  Fri Mar  9 19:51:01 2012 thierry berger
## Last update Thu Aug 23 05:58:18 2012 thierry berger
##

SRC	=	Main.cpp \
		Vegetable.cpp \
		World.cpp \
		GameObject.cpp \
		Hotdog.cpp

NAME	=	hotDog

LIB	=	-lsfml-graphics -lsfml-window -lsfml-system -lBox2D

CC	=	g++

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -ansi -pedantic

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(LIB) $(SRC) -o $(NAME)

clean	:
		rm -rf *~ $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
