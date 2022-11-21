#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen (src);
	// if (size > 0)
	// {
	if (size == 0)
		return (k);
	while (i < k && i + 1< size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	// }
	return (k);
}