/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:06:05 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/20 00:14:09 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sb_specifier(char spec, va_list *pargs)
{
	if (spec == 0)
		return (0);
	if (spec == 'c')
		return (ft_printchar(va_arg(*pargs, int)));
	if (spec == 's')
		return (ft_printstr(va_arg(*pargs, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(*pargs, int)));
	if (spec == 'u')
		return (ft_print_uint(va_arg(*pargs, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_print_hex(va_arg(*pargs, unsigned int), spec));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(*pargs, unsigned long)));
	if (spec == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &spec, 1));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += sb_specifier(format[i + 1], &args);
			i += 1 + 1 * (format[i + 1] != 0);
			continue ;
		}
		len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
#include <limits.h>
int main()
{
	//printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% '
	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 
	'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 
	'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% 
	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 
	'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', 
	"0", 0, 0 ,0 ,0, 42, 0);
}
*/