##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SHELL		=	bash

CXX			=	g++

SRC			=	src/Engine.cpp		\
				src/Data.cpp		\
				src/AGameObject.cpp	\
				src/ACollider.cpp	\
				src/Core.cpp		\
				src/Display.cpp		\
				src/Scene.cpp		\
				src/Window.cpp		\
				src/ATransform.cpp	\
				src/Vector2int.cpp	\
				src/ASprite.cpp

CXXFLAGS	=	-W -Wall -Wextra -Wpedantic -Wpadded -std=c++17 -I include -fms-extensions -O3 -fPIC

LDLIBS		=	-lsfml-system -lsfml-graphics -lsfml-window

LDFLAGS		=	$(LDLIBS) -shared

OBJ			=	$(SRC:.cpp=.o)

NAME		=	libwarden.so

all:    $(NAME) ## Build

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

lib: $(OBJ)
lib: LDFLAGS = $(LDLIBS) ## Build a static lib (.a)
lib: NAME = worden.a
lib:
	ar rc $(NAME) $(OBJ)

mac_lib: CXX = clang++ ## Build a static lib for mac
mac_lib: lib

mac: CXX = clang++ ## Build for mac
mac: all

debeug: CXXFLAGS += -g3 ## Build with debeug symbols
debeug: all

mac_debeug: CXX = clang++
mac_debeug: debeug

clean: ## Remove useless files
	rm -f *~
	rm -f $(OBJ)

fclean: clean ## Restart to 0
	rm -f $(NAME)

re:     fclean all

tests_run: ## Run unit tests

docker_test: fclean ## Run a docker for testing
	docker run --rm -v `pwd`:/project -it epitech zsh

help: ## Display help
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: all clean fclean
