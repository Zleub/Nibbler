NAME =	libd1.so
INCS =	$(subst .cpp,.hpp,$(SRC))
OBJ =	$(subst .cpp,.o,$(SRC))
SRC =	src/test.cpp\
		src/Nibbler.cpp\
		# src/AGlib.cpp\

CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra

INC		=	-Iinc -I../../inc
INC		+=	-Iext/SFML-2.2/include
INC		+=	-Iext/lua-5.3.0/src/

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -fPIC -o $@ $^ -rpath ext/SFML-2.2/extlibs

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
