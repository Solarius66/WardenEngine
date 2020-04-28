##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	arcade

LOAD	=	-ldl -lstdc++fs -lsfml-system -lsfml-graphics -lsfml-window -lsfml-system

INC	=	 -Iinclude/engine -Iinclude/engine/data -Iinclude/engine/core -Iinclude/engine/display -Iinclude/engine/error -Iinclude/Menu

SRC	=	src/engine/main.cpp \
				src/engine/GameEngine.cpp	\
				\
				src/engine/data/SceneManager.cpp	\
				src/engine/data/AScene.cpp	\
				src/engine/data/AGameObject.cpp	\
				src/engine/data/ACollider.cpp	\
				src/engine/data/MeshRenderer.cpp	\
				src/engine/data/TextRenderer.cpp	\
				src/engine/data/Transform.cpp	\
				\
				src/engine/core/Core.cpp	\
				\
				src/engine/display/Display.cpp	\
				src/engine/display/SFMLModule.cpp	\
				\
				src/Menu/MenuEntity.cpp	\
				src/Menu/MenuScene.cpp	\
				src/Menu/MoveMenuEntity.cpp	\
				src/Menu/TextBox.cpp	\
				src/Menu/FillNameField.cpp	\
				src/Menu/ScoreManager.cpp

OBJ	=	$(SRC:.cpp=.o)

DIROBJ	=	$($(OBJ))

CC		=	g++

CXXFLAGS	+=	-W -Wall -Wextra -pedantic -std=gnu++14 -rdynamic

all: $(NAME)


%.o:		%.cpp
	$(CC) $(INC) $(CXXFLAGS) $< -c -o $@

$(NAME):		$(OBJ)
	$(CC) $(CXXFLAGS) $(INC) $(OBJ) -o $(NAME) $(LOAD)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

default:	all

.PHONY: all clean fclean re
