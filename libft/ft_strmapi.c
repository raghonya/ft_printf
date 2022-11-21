#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// char f(unsigned int i, char c)
// {
// 	char k;

// 	k = c + i + 2;
// 	return k;
// }

// int main()
// {
// 	printf ("%s\n", ft_strmapi("ABCDEFG", f));
// }