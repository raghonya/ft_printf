/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:50:51 by raghonya          #+#    #+#             */
/*   Updated: 2023/01/23 20:50:52 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "printfLib/libft.h"
#include <stdio.h>

void	putuint(unsigned int n, unsigned int *count)
{
	if (n > 9)
		putuint (n / 10, count);
	ft_putchar_fd (n % 10 + 48, STDOUT_FILENO);
	*count += 1;
}

void	putlowhex(unsigned int n, unsigned int *count)
{
	if (n > 15)
		putlowhex (n / 16, count);
	ft_putchar_fd ("0123456789abcdef"[n % 16], STDOUT_FILENO);
	*count += 1;
}

void	putuphex(unsigned int n, unsigned int *count)
{
	if (n > 15)
		putuphex (n / 16, count);
	ft_putchar_fd ("0123456789ABCDEF"[n % 16], STDOUT_FILENO);
	*count += 1;
}

int	check_perc(int *i, const char *s, va_list *a, unsigned int *count)
{
	if (s[*i + 1] == '%')
	{
		ft_putchar_fd ('%', STDOUT_FILENO);
		*count += 1;
	}
	else if (s[*i + 1] == 'c')
	{
		ft_putchar_fd (va_arg(*a, int), STDOUT_FILENO);
		*count += 1;
	}
	else if (s[*i + 1] == 's')
		ft_putstr_fd (va_arg(*a, char *), STDOUT_FILENO, count);
	else if (s[*i + 1] == 'i' || s[*i + 1] == 'd')
		ft_putnbr_fd (va_arg(*a, int), STDOUT_FILENO, count);
	else if (s[*i + 1] == 'u')
		putuint (va_arg(*a, unsigned int), count);
	else if (s[*i + 1] == 'x')
		putlowhex (va_arg(*a, unsigned int), count);
	else if (s[*i + 1] == 'X')
		putuphex (va_arg(*a, unsigned int), count);
	else if (s[*i + 1] == 'p')
		checkptr (va_arg(*a, uintptr_t), count);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int				i;
	unsigned int	count;
	va_list			arg;

	i = 0;
	count = 0;
	va_start (arg, s);
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			if (check_perc (&i, s, &arg, &count))
				i++;
		}
		else
		{
			ft_putchar_fd (s[i], 1);
			count++;
		}
		i++;
	}
	va_end (arg);
	return (count);
}

// int main()
// {
// 	printf ("OR:\n!%2lc!", (char)221);
	// ft_printf ("MY:\n!%2lc!", (char)221);
// 	int a;
// 	// int i = 0;
// 	// char *s = "1234";
// 	// int *c = NULL;
// 	// int *c1 = malloc(100);
// 	// char **c2 = NULL;
// 	// unsigned int *c3 = malloc(100);
// 	// size_t *c4 = malloc(100);
// 	// long *c5 = malloc(100);
// 	// int *c6 = NULL;
// 	// int *c7 = NULL;
// 	// int *c8 = NULL;

// 	// while (i < 10)
// 	// {
// 	// 	c1[i] = i + 4;
// 	// 	c3[i] = i + 7;
// 	// 	c4[i] = i + 45;
// 	// 	c5[i] = i + 11;
// 	// 	i++;
// 	// }
// 	printf ("\n\n\n");
// 	// printf ("PTRS\n");
// 	// a = ft_printf ("lowhex->%x, ", 641279);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", 641279);printf ("qanak %d\n", a);
// 	// a = ft_printf ("ptr->%p, ", c1);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", c1);printf ("qanak %d\n\n\n", a);
// 	// a = ft_printf ("lowhex->%x, ", -777);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", -777);printf ("qanak %d\n\n", a);
// 	// a = ft_printf ("ptr->%p, ", &c2);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", &c2);printf ("qanak %d\n\n\n", a);

// 	// a = ft_printf ("lowhex->%x, ", 5842);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", 5842);printf ("qanak %d\n\n", a);
// 	// a = ft_printf ("ptr->%p, ", c3);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", c3);printf ("qanak %d\n\n\n", a);

// 	// a = ft_printf ("lowhex->%x, ", 125613);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", 125613);printf ("qanak %d\n\n", a);
// 	// a = ft_printf ("ptr->%p, ", c4);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", c4);printf ("qanak %d\n\n\n", a);

// 	// a = ft_printf ("lowhex->%x, ", 456+4156);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", 456+4156);printf ("qanak %d\n\n", a);
// 	// a = ft_printf ("ptr->%p, ", c5);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", c5);printf ("qanak %d\n\n\n", a);

// 	a = ft_printf ("lo%%whex->%x\nunsint->%u\nuphex->%X\nint->%i\nstr->%s\nptr->%p\n", -440, -440, -440, 577, NULL, NULL);printf ("MY: %d\n\n", a);
// 	   a = printf ("lo%%whex->%x\nunsint->%u\nuphex->%X\nint->%i\nstr->%s\nptr->%p\n", -440, -440, -440, 577, NULL, NULL);printf ("IS: %d\n\n", a);
// 	// a = ft_printf ("lowhex->%x, ", -152);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("lowhex->%x, ", -152);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("lowhex->%x, ", 4713);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("lowhex->%x, ", 4713);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("uphex->%X, ", -152);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("uphex->%X, ", -152);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("uphex->%x, ", 4713);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("uphex->%x, ", 4713);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("int->%i, ", 2147483645);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("int->%i, ", 2147483645);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("str->%s, ", NULL);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("str->%s, ", NULL);printf ("iskakani tiv: %d\n\n", a);

// 	// a = ft_printf ("lowhex->%x, ", "baylsueu");printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", "baylsueu");printf ("qanak %d\n", a);
// 	// a = ft_printf ("ptr->%p, ", "baylsueu");printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", "baylsueu");printf ("qanak %d\n\n", a);

// 	// a = ft_printf ("lowhex->%x, ", as);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", as);printf ("qanak %d\n", a);
// 	// a = ft_printf ("ptr->%p, ", as);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", as);printf ("qanak %d\n\n", a);

// 	// a = ft_printf ("lowhex->%x, ", &b);printf ("qanak %d\n", a);
// 	//    a = printf ("lowhex->%x, ", &b);printf ("qanak %d\n", a);
// 	// a = ft_printf ("ptr->%p, ", &b);printf ("qanak %d\n", a);
// 	//    a = printf ("ptr->%p, ", &b);printf ("qanak %d\n\n", a);
// 	// a = ft_printf ("ptr->%p, ", NULL);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("ptr->%p, ", NULL);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("ptr->%p, ", "asdasd");printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("ptr->%p, ", "asdasd");printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("char->%c, ", 77);printf ("im gracitiv: %d\n", a);
// 	//    a = printf ("char->%c, ", 77);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("%kyawuid, ", 44415641568456132);printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("%kyawuid, ", 44415641568456132);printf ("iskakani tiv: %d\n\n", a);
// 	// a = ft_printf ("sagbdyuiasdh%VH%B%JB%J%%jubnhj, %");printf ("im graci tiv: %d\n", a);
// 	//    a = printf ("sagbdyuiasdh%VH%B%JB%J%%jubnhj, %");printf ("iskakani tiv: %d\n\n", a);
// 	// printf ("%#x\n", 485);
// 	// // printf ("%d\n", a);

// 	// free (c1);	
// 	// free (c3);	
// 	// free (c4);	
// 	// free (c5);	
// }
