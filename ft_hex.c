/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:40:55 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/20 00:14:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sb_puthex(unsigned long num, char *set)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += sb_puthex(num / 16, set);
	len += write(1, &set[num % 16], 1);
	return (len);
}

int	ft_print_hex(unsigned int num, char spec)
{
	if (spec == 'X')
		return (sb_puthex(num, "0123456789ABCDEF"));
	return (sb_puthex(num, "0123456789abcdef"));
}

int	ft_print_ptr(unsigned long num)
{
	write(1, "0x", 2);
	return (2 + sb_puthex(num, "0123456789abcdef"));
}
