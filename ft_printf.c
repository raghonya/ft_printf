#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>

void	ft_putuint(unsigned int n, unsigned int *count)
{
	if (n > 9)
		ft_putuint (n / 10, count);
	ft_putchar_fd (n % 10 + 48, STDOUT_FILENO);
	*count += 1;
}

void	ft_putlowhex(unsigned int n, unsigned int *count)
{
	if (n > 15)
		ft_putlowhex (n / 16, count);
	ft_putchar_fd ("0123456789abcdef"[n % 16], STDOUT_FILENO);
	*count += 1;
}

void	ft_putuphex(unsigned int n, unsigned int *count)
{
	if (n > 15)
		ft_putuphex (n / 16, count);
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
		ft_putuint (va_arg(*a, unsigned int), count);
	else if (s[*i + 1] == 'x')
		ft_putlowhex (va_arg(*a, unsigned int), count);
	else if (s[*i + 1] == 'X')
		ft_putuphex (va_arg(*a, unsigned int), count);
	else if (s[*i + 1] == 'p')
		checkptr (a, count);
	else
		return (0);
	return (1);
}

int ft_printf(const char *s, ...)
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
	return count;
}

int main()
{
	int a;
	int b = 15;
	int *c = &b;
	void *as;

	printf ("\n");
	// a = ft_printf ("lowhex->%x\nunsint->%u\nuphex->%X\nint->%i\nstr->%s\nptr->%p\n", -440, -440, -440, 577, NULL, s);printf ("MY: %d\n\n", a);
	// a = printf ("lowhex->%x\nunsint->%u\nuphex->%X\nint->%i\nstr->%s\nptr->%p\n", -440, -440, -440, 577, NULL, s);printf ("IS: %d\n\n", a);
	a = ft_printf ("lowhex->%x, ", -152);printf ("im graci tiv: %d\n", a);
	   a = printf ("lowhex->%x, ", -152);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("lowhex->%x, ", 4713);printf ("im graci tiv: %d\n", a);
	   a = printf ("lowhex->%x, ", 4713);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("uphex->%X, ", -152);printf ("im graci tiv: %d\n", a);
	   a = printf ("uphex->%X, ", -152);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("uphex->%x, ", 4713);printf ("im graci tiv: %d\n", a);
	   a = printf ("uphex->%x, ", 4713);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("unsint->%u, ", 641279);printf ("im graci tiv: %d\n", a);
	   a = printf ("unsint->%u, ", 641279);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("unsint->%u, ", -777);printf ("im graci tiv: %d\n", a);
	   a = printf ("unsint->%u, ", -777);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("int->%i, ", 2147483645);printf ("im graci tiv: %d\n", a);
	   a = printf ("int->%i, ", 2147483645);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("str->%s, ", NULL);printf ("im graci tiv: %d\n", a);
	   a = printf ("str->%s, ", NULL);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("ptr->%p, ", NULL);printf ("im graci tiv: %d\n", a);
	   a = printf ("ptr->%p, ", NULL);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("ptr->%p, ", as);printf ("im graci tiv: %d\n", a);
	   a = printf ("ptr->%p, ", as);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("char->%c, ", 77);printf ("im gracitiv: %d\n", a);
	   a = printf ("char->%c, ", 77);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("%kyawuid, ", 44415641568456132);printf ("im graci tiv: %d\n", a);
	   a = printf ("%kyawuid, ", 44415641568456132);printf ("iskakani tiv: %d\n\n", a);
	a = ft_printf ("sagbdyuiasdh%VH%B%JB%J%%jubnhj, ");printf ("im graci tiv: %d\n", a);
	   a = printf ("sagbdyuiasdh%VH%B%JB%J%%jubnhj, ");printf ("iskakani tiv: %d\n\n", a);
	printf ("%#x\n", 485);
	// printf ("%d\n", a);
}