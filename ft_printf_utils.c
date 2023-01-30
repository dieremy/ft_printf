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

int	print_int(int n)
{
	size_t	len;

	len = ft_length(n);
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		print_int(n / 10);
		print_int(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (len);
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

int	print_uint(unsigned int n)
{
	size_t	ulen;

	ulen = ft_ulength(n);
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		print_int(n / 10);
		print_int(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (ulen);
}

int	len_hex(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	print_hex(unsigned int n, const char ptr)
{
	unsigned int	nb;

	nb = len_hex(n);
	if (n > 15)
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
	return (nb);
}
int	len_p(uintptr_t nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	print_p(uintptr_t n)
{
	unsigned int	nb;

	nb = len_hex(n);
	
	if (n > 15)
	{
		print_p(n / 16);
		print_p(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(48 + n);
		else
			ft_putchar('a' + n - 10);
	}
	return (nb);
}
