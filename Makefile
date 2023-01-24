NAME = libftprintf.a

LIBNAME = printfLib

CFLAGS = -Wall -Wextra -Werror

LIBA = printfLib/libft.a

FILES = $(wildcard *.c);

OBJ = $(FILES:.c=.o)

all: lib $(NAME)

lib:
	make -C $(LIBNAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	
libfclean:
	make fclean -C $(LIBNAME)

clean:
	rm -f *.o

fclean: libfclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib libfclean
