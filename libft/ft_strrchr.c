#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	while (1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		if (i == 0)
			return (NULL);
		i--;
	}
}