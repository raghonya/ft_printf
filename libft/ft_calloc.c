#include "libft.h"

void	*ft_calloc(size_t size, size_t byte)
{
	size_t	i;
	void	*arr;

	i = 0;
	arr = malloc(size * byte);
	if (!arr || !size || !byte)
		return (NULL);
	while (i < size * byte)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}