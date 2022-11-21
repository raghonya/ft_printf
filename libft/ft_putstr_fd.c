#include "libft.h"

void	ft_putstr_fd(char *s, int fd, unsigned int *count)
{
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		*count += 6;
		return ;
	}
	write (fd, s, ft_strlen (s));
	*count += ft_strlen (s);
}