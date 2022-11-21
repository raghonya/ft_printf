NAME = libftprintf.a

CC = gcc

CFLAGS = -c #-Wall -Wextra -Werror

LIBA = ./libft/libft.a

LIB = make -C libft

FILES = $(wildcard *.c)

OBJ = $(FILES:.c=.o)

all: libft $(NAME)
	$(LIB); $(CC) -o main *.c $(NAME) $(LIBA); ./main.exe

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(CFLAGS) $(FILES)

libfclean:
	 $(LIB) fclean

clean:
	rm -f *.o

fclean: libfclean clean
	rm -f libftprintf.a *.exe *.out

re: fclean all

.PHONY: all clean fclean re