#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_lenght(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while ((nb / 10) > 0 && i++)
		nb = nb / 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_lenght(nb) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		new[0] = '-';
	}
	new[--len] = '\0';
	if (nb == 0)
		new[0] = '0';
	while (nb > 0)
	{
		new[--len] = (nb % 10) + '\0';
		nb /= 10;
	}
	return (new);
}

int	ft_putnbr(int n)
{
	int		number;
	char	*str_nb;

	str_nb = ft_itoa(n);
	number = ft_putstr(str_nb);
	free(str_nb);
	return (number);
}

int	print_hex()