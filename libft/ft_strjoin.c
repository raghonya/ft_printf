#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k; 
	char	*s;

	i = 0;
	k = 0;
	s = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			s[i] = s1[i];
		else
			s[i] = s2[k++];
		i++;
	}
	s[i] = 0;
	return (s);
}