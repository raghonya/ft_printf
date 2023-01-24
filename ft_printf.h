#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "printfLib/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		check_perc(int *i, const char *s, va_list *a, unsigned int *count);
void	ft_putnbr_fd(int n, int fd, unsigned int *count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd, unsigned int *count);
void	putuint(unsigned int n, unsigned int *count);
void	putlowhex(unsigned int n, unsigned int *count);
void	putuphex(unsigned int n, unsigned int *count);
void	checkptr(uintptr_t n, unsigned int *count);

#endif