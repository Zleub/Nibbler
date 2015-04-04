NAME =	bin/Client
INCS =	$(subst .cpp,.hpp,$(SRC))
OBJ =	$(subst .cpp,.o,$(SRC))
SRC =	src/Glib.cpp\
		src/Glib_Exception.cpp\
		main.cpp

CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra

INC		=	-Iinc
INC		+=	-Iext/SFML-2.2/include
INC		+=	-Iext/lua-5.3.0/src/

LIBS	=	-Lext/SFML-2.2/lib
LIBS	+=	-lsfml-graphics
LIBS	+=	-lsfml-window
LIBS	+=	-lsfml-system
LIBS	+=	-lsfml-audio
# LIBS	+=	-lsfml-network

#LIBS	+=	-Llib/lua-5.3.0/src/
#LIBS	+=	-llua


.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) -rpath ext/SFML-2.2/extlibs

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
