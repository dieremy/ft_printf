/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:13:53 by robegarc          #+#    #+#             */
/*   Updated: 2023/01/28 10:17:34 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_length(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb / 10 > 0 && i++)
		nb = nb / 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_length(nb) + 1;
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
		new[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (new);
}

int	print_int(int n)
{
	int		number;
	char	*str_nb;

	str_nb = ft_itoa(n);
	number = ft_putstr(str_nb);
	free(str_nb);
	return (number);
}

int	ft_ulength(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*new;
	int		len;

	len = ft_ulength(n) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	new[--len] = 0;
	while (n)
	{
		new[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (new);
}

int	print_uint(unsigned int n)
{
	char			*str_num;
	unsigned int	num;

	if (n == 0)
		num = ft_putchar(48);
	str_num = ft_uitoa(n);
	num = ft_putstr(str_num);
	free(str_num);
	return (num);
}

int	print_hex(unsigned int n, const char ptr)
{
	int	i;

	i = 0;
	if (n > 15 && i++)
	{
		print_hex(n / 16, ptr);
		print_hex(n % 16, ptr);
	}
	else
	{
		if (n < 10)
			ft_putchar(48 + n);
		else
		{
			if (ptr == 'x')
				ft_putchar('a' + n - 10);
			if (ptr == 'X')
				ft_putchar('A' + n - 10);
		}
	}
	return (i);
}
