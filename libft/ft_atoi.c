int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\f' || s[i] == '\r'
		|| s[i] == '\n' || s[i] == '\v' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] > 47 && s[i] < 58)
		n = (n * 10) + (s[i++] - 48);
	return (sign * n);
}