/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:10:36 by robegarc          #+#    #+#             */
/*   Updated: 2023/01/28 10:10:57 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //nope

int		ft_putstr(char *s);
int		ft_putchar(int c);
int		print_int(int n);
int		ft_printf(const char *ptr, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int     print_uint(unsigned int n);
int	    print_hex(unsigned int n, const char ptr);


# endif
