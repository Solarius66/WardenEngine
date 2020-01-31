##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SHELL		=	bash

CC		=	g++

SRC		=	src/main.cpp

SFFLAGS		=	-lsfml-system -lsfml-graphics -lsfml-window

CPPFLAGS	=	-W -Wall -Wextra -Wpedantic -Wpadded -std=c++17 -I include -O3

LDFLAGS		=	$(SFFLAGS)

OBJ		=	$(SRC:.cpp=.o)

NAME		=	test

all:    $(NAME) ## Build

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

mac: CC = clang++
mac: all

debeug: CPPFLAGS += -g3 ## Build with debeug symbols
debeug: all

mac_debeug: CC = clang++
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

doc: ## Generates doxygen documentation
	doxygen doxyfile

help: ## Display help
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: all clean fclean
