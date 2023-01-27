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
		out += ft_putnbr(va_arg(v, int));
	else if (ptr == '%')
		out += ft_putchar('%');
	// else if (ptr == 'p')
	// 	out += 
	// else if (ptr == 'u')
	// 	out += 
	// else if (ptr == 'x' || ptr == 'X')
	// 	out += 
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
	int i = 1 ;
	int j = 2002;
	ft_printf("%s\n", str);
	ft_printf("%c\n", c);
	ft_printf("%c\n", s);
	ft_printf("%%\n");
	ft_printf("int i = %d\n", i);
	ft_printf("hello fucking world\n");
	printf("void = %p\nvoid = %p\n", ciao, ciao + 1);
	printf("percentuale %%\n");
	ft_printf("%i\n", j);

	char *num = ft_itoa(0);
	printf("itoa = %s\n", num);
	for (int i = 0; i < 3; i++)
		printf("[%d]\n", ciao[i]);
}