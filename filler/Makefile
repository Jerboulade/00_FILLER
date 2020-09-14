.PHONY: all clean fclean re

NAME = jecarere.filler
SRC = ./sources/filler.c ./sources/get_info.c ./sources/get_placement.c \
	./sources/init_game.c ./sources/parsing.c ./sources/put_piece.c \
	./sources/tool.c
O = ./sources/filler.o ./sources/get_info.o ./sources/get_placement.o \
	./sources/init_game.o ./sources/parsing.o ./sources/put_piece.o \
	./sources/tool.o
CC = gcc
CFLAG = -Wall -Wextra -Werror
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(CFLAG) $(LIB) -o $(NAME) $(SRC) -I./includes
	@echo COMPILATION FILLER OK

clean:
	@make -C ./libft/ fclean
	@/bin/rm -f $(O)
	@echo CLEAN FILLER OK

fclean: clean
	@make -C ./libft/ fclean
	@rm -f $(NAME)
	@echo FCLEAN FILLER OK

re: fclean all
