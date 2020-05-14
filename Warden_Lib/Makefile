##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
####
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

## ------ COLORS ------ ##

DEFAULT     =   "\033[00m"
RED         =   "\033[31m"
GREEN       =   "\033[1;32m"
TEAL        =   "\033[1;36m"
YELLOW      =   "\033[1;7;25;33m"
MAGENTA     =   "\033[1;3;4;35m"
ERROR       =   "\033[5;7;1;31m"
BLINK       =   "\033[5m"
END         =   "\n"

CXX		    =   clang++

SRC	        =   src/engine/GameEngine.cpp           \
			    src/engine/data/SceneManager.cpp	\
			    src/engine/data/AScene.cpp          \
			    src/engine/data/AGameObject.cpp     \
			    src/engine/data/ACollider.cpp       \
			    src/engine/data/MeshRenderer.cpp	\
			    src/engine/data/TextRenderer.cpp	\
			    src/engine/data/Transform.cpp       \
			    src/engine/core/Core.cpp            \
			    src/engine/display/Display.cpp      \
			    src/engine/display/SFMLModule.cpp

OBJ	        =   $(SRC:.cpp=.o)

NAME        =   ./libwarden.so

LDFLAGS     =   -shared

LDLIBS	    =   -ldl -lstdc++fs -lsfml-system -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS    =   -W -Wall -Wextra -pedantic -std=gnu++14 -I /usr/local/include/ -I include/engine -I include/engine/data -I include/engine/core -I include/engine/display -I include/engine/error -fPIC

all: $(NAME)
	@printf "["$(GREEN)"INFO"$(DEFAULT)"] Compiler: $(CXX)"$(END)

%.o:        %.cpp
	@$(CXX)  $(CXXFLAGS) -c $< -o $@ && \
	printf "["$(GREEN)"OK"$(DEFAULT)"] "$(TEAL)$<$(DEFAULT)" -----> "$(GREEN)$@$(DEFAULT)$(END) || \
	printf "["$(RED)"KO"$(DEFAULT)"] "$(BLINK)$(YELLOW)$^$(DEFAULT)$(END) 1>&2

$(NAME):    $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
	@printf "["$(GREEN)"OK"$(DEFAULT)"]"$(TEAL)" Done : "$@$(DEFAULT)$(END) || \
	printf "["$(RED)"KO"$(DEFAULT)"]"$(BLINK)$(YELLOW)$(NAME)$(DEFAULT)$(END) 1>&2
	cp $(NAME) ../Warden_Software/libs/

clean:
	@rm -rf $(OBJ)
	@printf "["$(RED)"DEL"$(DEFAULT)"] $(OBJ)"$(END)

fclean:	clean
	@rm -f $(NAME)
	@printf "["$(RED)"DEL"$(DEFAULT)"] $(NAME)"$(END)

re:	fclean all

default:	all

.PHONY: all clean fclean re
