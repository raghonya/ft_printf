#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!dup)
		return (NULL);
	while (i < ft_strlen(s))
	{
		*(dup + i) = *(s + i);
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}