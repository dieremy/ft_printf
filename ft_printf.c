/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:11:09 by robegarc          #+#    #+#             */
/*   Updated: 2023/01/28 10:13:32 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output(va_list v, const char ptr)
{
	int	out;

	out = 0;
	if (ptr == 'c')
		out += ft_putchar(va_arg(v, int));
	else if (ptr == 's')
		out += ft_putstr(va_arg(v, char *));
	else if (ptr == 'd' || ptr == 'i')
		out += print_int(va_arg(v, int));
	else if (ptr == '%')
		out += ft_putchar('%');
	// else if (ptr == 'p')
	// 	out += 
	else if (ptr == 'u')
		out += print_uint(va_arg(v, unsigned int));
	else if (ptr == 'x' || ptr == 'X')
	 	out += print_hex(va_arg(v, unsigned int), ptr);
	return (out);
}

int	ft_printf(char const *ptr, ...)
{
	int		i;
	int		out;
	va_list	v;

	i = 0;
	out = 0;
	va_start(v, ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			out += ft_output(v, ptr[i + 1]);
			i++;
		}
		else
			out += ft_putchar(ptr[i]);
		i++;
	}
	va_end(v);
	return (out);
}

int main()
{
	char str[] = "hello world";
	char c = '%';
	char s = 'F';
	int ciao[] = {4, 5, 6};
	int i = 13;
	int j = 2002;
	unsigned int ui = 0;
	unsigned int uu = -789;
	// ft_printf("-s = %s\n", str);
	// ft_printf("-c = %c\n", c);
	// ft_printf("-c = %c\n", s);
	// ft_printf("percentuale = %%\n");
	// ft_printf("-d = %d\n", i);
	// ft_printf("-stringa intput = hello fucking world\n");
	// printf("void = %p\nvoid = %p\n", ciao, ciao + 1);
	// printf("percentuale %%\n");
	// ft_printf("-i = %i\n", j);
	// ft_printf("-u = %u\n", ui);
	// printf("real -u = %u\n", ui);
	// ft_printf("quiiiiiiiiiiiiiiii-u = %u\n", -789);
	// ft_printf("quaaaaaaaaaaaaaaaa-u = %u\n", -256);
	// ft_printf("quuuuuuuuuuuuuuuuu-u = %u\n", -123);
	// printf("reali -u = %u\n", -789);
	// printf("reala -u = %u\n", -256);
	// printf("realu -u = %u\n", -123);
	ft_printf("-X = %X\n", 1234);
	printf("-X = %X\n", 1234);

}
