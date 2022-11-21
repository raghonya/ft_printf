int	ft_isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) && ft_isdigit(c));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}