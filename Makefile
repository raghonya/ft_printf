NAME = libftprintf.a

CFLAGS =# -Wall -Wextra -Werror

LIBNAME = printfLib

LIBA = printfLib/libft.a

FILES = $(wildcard *.c)

LIBFILES = $(wildcard $(LIBNAME)/*.c)

OBJ = $(FILES:.c=.o)

LIBOBJ = $(LIBFILES:.c=.o)

all: lib $(NAME)

lib:
	@make -C $(LIBNAME)

$(NAME): $(OBJ) $(LIBOBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBOBJ)
	
libfclean:
	make fclean -C $(LIBNAME)

clean:
	rm -f *.o

fclean: libfclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib libfclean
