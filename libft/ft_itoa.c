#include "libft.h"

static int	count(long long int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb)
	{	
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				i;
	int				size;
	char			*s;
	long long int	nb;
	
	i = 0;
	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	size = count (nb);
	s = malloc (sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		s[i++] = '-';
		nb *= -1;
	}
	s[size--] = 0;
	while (i <= size)
	{
		s[size--] = (nb % 10 + 48);
		nb /= 10;
	}
	return (s);
}