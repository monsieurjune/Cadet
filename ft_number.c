/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:41:01 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/20 00:15:10 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (num < 0)
		{
			num *= -1;
			len += write(1, "-", 1);
		}
		if (num >= 10)
			len += ft_print_int(num / 10);
		len += write(1, &"0123456789"[num % 10], 1);
	}
	return (len);
}

int	ft_print_uint(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_print_int(num / 10);
	len += write(1, &"0123456789"[num % 10], 1);
	return (len);
}
