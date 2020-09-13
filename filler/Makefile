.PHONY: all clean fclean re

NAME = jecarere.filler
SRC = ./sources/*.c
CC = gcc
CFLAG = -Wall -Wextra -Werror
O = ./sources/*.o
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
