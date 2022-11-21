#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (n--)
		*s11++ = *s22++;
	return (s1);
}

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (s22 < s11)
	{
		s11 += n;
		s22 += n;
		while (n--)
			*--s11 = *--s22;
	}
	else
		while (n--)
			*s11++ = *s22++;
	return (s1);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	
	s1 = (unsigned char *)s;
	while (*s1 && n--)
	{
		if (*s1 == c)
			return (s1);
		s1++;
 	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (i < n && s11[i] == s22[i])
		i++;
	return (s11[i] - s22[i]);
}

// 	// printf ("\n\n");
// 	int i = 0;
// 	int *a1 = malloc (1000);
// 	int *a2 = malloc (1000);
// 	char *s1 = malloc(2000);
// 	char *s2 = malloc(2000);
// 	char *s11 = malloc(2000);
// 	char *s12 = malloc(2000);
// 	char *s21 = malloc(2000);
// 	char *s22 = malloc(2000);
// 	// printf ("arr = { ");
// 	// i = 0;
// 	// int b1[] = {0,1,2,3,4,5,6,7,8,9};
// 	// int b2[] = {0,1,2,3,4,5,6,7,8,9};
// 	//while (i < 9)
// 		//printf ("%d ", a2[i++]);
// 	//printf ("}\n");

// 	// ft_memcpy (a1, b1, 36);
// 	// printf ("im gracy: ");
// 	// for (size_t i = 0; i < 10; i++)
// 	// 	printf("%d ", a1[i]);
// 	i = 0;
// 	while (i < 15)
// 	{
// 		s1[i] = i + 97;
// 		s2[i] = i + 97;
// 		s11[i] = i + 110;
// 		s12[i] = 'b';
// 		s21[i] = i + 110;
// 		s22[i] = 'b';
// 		a1[i] = i;
// 		a2[i] = i;
// 		i++;
// 	}
// 	printf ("FT_MEMCPY RESULTS!!!\n1\n");
// 	ft_memcpy (&s1[2], s1, 16); printf ("im gracy: %s\n", s1);
// 	memcpy (&s2[2], s2, 16); printf ("iskakany: %s\n", s2);
// 		// printf ("2\n");
// 	// s22 = ft_memcpy (a2, 't', 8); printf ("im gracy: %s\n", s22);
// 	// s21 = memcpy (a2, 't', 8); printf ("iskakany: %s\n", s21);
// 	// 	printf ("3\n");

// 	// s22 = ft_memcpy ("hayvanner blyat", 'e', 8); printf ("im gracy:%s\n", s22);
// 	// s21 = memcpy ("hayvanner blyat", 'e', 8); printf ("iskakany: %s\n", s21);
// 	// 	printf ("4\n");

// 	// s22 = ft_memcpy ("vat chi vat chi", 'h', 4); printf ("im gracy: %s\n", s22);
// 	// s21 = memcpy ("vat chi vat chi", 'h', 4); printf ("iskakany: %s\n", s21);
// 	printf ("\n\n");
// 	i = 0;
// 	while (i < 15)
// 	{
// 		s1[i] = i + 97;
// 		s2[i] = i + 97;
// 		i++;
// 	}
// 	ft_memmove (&a1[2], a1, 4);i = 0;printf ("im gracy: ");while (i < 15){printf ("%d ", a1[i]);i++;}printf ("\n");
// 	memmove (&a2[2], a2, 4);i = 0;printf ("iskakany: ");while (i < 15){printf ("%d ", a2[i]);i++;}printf ("\n");
// 		printf ("\n");
// ///////////////////////////////   MEMCMP   ////////////////////////////////////////
// int	main()
// {
// 	int a;
// 	printf ("1\n");
// a = ft_memcmp ("lavacava", "lavahava", 0); printf ("im gracy: %d\n", a);
// a = memcmp ("lavacava", "lavahava", 0); printf ("iskakany: %d\n", a);
// 	printf ("2\n");

// a = ft_memcmp ("abcdefg", "abcdnfg", 5); printf ("im gracy: %d\n", a);
// a = memcmp ("abcdefg", "abcdnfg", 5); printf ("iskakany: %d\n", a);
// 	printf ("3\n");

// a = ft_memcmp ("hayvanner blyat", "hastat", 4); printf ("im gracy: %d\n", a);
// a = memcmp ("hayvanner blyat", "hastat", 4); printf ("iskakany: %d\n", a);
// 	printf ("4\n");

// a = ft_memcmp ("vat chi vat chi", "vat chi vat a", 15); printf ("im gracy: %d\n", a);
// a = memcmp ("vat chi vat chi", "vat chi vat a", 15); printf ("iskakany: %d\n", a);
// 	printf ("5\n");

// a = memcmp ("abcd", "abcd",    1000000); printf ("iskakany: %d\n", a);
// a = ft_memcmp ("abcd", "abcd", 1000000); printf ("im gracy: %d\n", a);
// 	printf ("\n\n");
// }
// */