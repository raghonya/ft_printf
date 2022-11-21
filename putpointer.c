#include "printf.h"
#include "./libft/libft.h"

int	ft_putptr(unsigned int n, char *s, unsigned int *index)
{
	// int		i;
	// // int a = 0;

	// i = 10;
	// if (n > 15)
	// 	i = ft_putptr(n / 16, s);
	// s[i] = "0123456789ABCDEF"[n % 16];
	// return i + 1;


	// unsigned int	count;

	if (n > 15)
	{
		*index += 1;
		ft_putptr(n / 16, s, index);
	}
	s[15 - (*index)--] = "0123456789ABCDEF"[n % 16];

}

void ft_putstrptr(char *s, unsigned int *count)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (!s[i])
			ft_putchar_fd ('0', STDOUT_FILENO);
		else
			ft_putchar_fd (s[i], STDOUT_FILENO);
	}
	*count += 16;
}

void	checkptr(va_list *a, unsigned int *count)
{
	char			*s;
	unsigned int	index;

	s = ft_calloc (16, 16);
	index = 0;
	ft_putptr (va_arg(*a, unsigned int), s, &index);
	ft_putstrptr (s, count);
	free (s);
}