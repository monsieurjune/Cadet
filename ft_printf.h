/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:59:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/19 23:33:51 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_printchar(char print);
int	ft_printstr(char *str);
int	ft_print_int(int num);
int	ft_print_uint(unsigned int num);
int	ft_print_hex(unsigned int num, char spec);
int	ft_print_ptr(unsigned long num);

#endif