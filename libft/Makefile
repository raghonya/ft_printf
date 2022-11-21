NAME = libft.a

CC = gcc

CFLAGS = -c #-Wall -Wextra -Werror 

FILES = $(wildcard ft_*.c)

OBJ = $(FILES:.c=.o)

all: $(NAME)
	$(CC) ../*.c $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(CFLAGS) $(FILES)

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a *.exe *.out

re: fclean all

.PHONY: all clean fclean re