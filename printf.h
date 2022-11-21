#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int		ft_putptr(unsigned int n, char *s, unsigned int *index);
void	ft_putstrptr(char *s, unsigned int *count);
void	checkptr(va_list *a, unsigned int *count);

#endif