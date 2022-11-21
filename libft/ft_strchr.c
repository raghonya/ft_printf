#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		if (s[i] == 0)
			return (NULL);
		i++;
 	}
}