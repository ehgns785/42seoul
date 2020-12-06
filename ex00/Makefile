CC = gcc
CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror
NAME = rush-02
SRC = $(shell echo ./src/*.c)
OBJ = $(SRC:.c=.o)

.PHONY:all clean fclean re
all: $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
