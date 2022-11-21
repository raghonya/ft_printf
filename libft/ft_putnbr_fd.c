#include "libft.h"

void	ft_putnbr_fd(int n, int fd, unsigned int *count)
{
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		nb *= -1;
		*count += 1;
	}
	if (nb > 9)
		ft_putnbr_fd (nb / 10, fd, count);
	ft_putchar_fd ((nb % 10) + 48, fd);
	(*count)++;
}