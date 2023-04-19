/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 05:08:08 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 07:25:06 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astable.h"

void	*ft_memset(void *ptr, int c, size_t byte)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < byte)
	{
		((unsigned char *)ptr)[i] = ((unsigned char *)&c)[0];
		i++;
	}
	return (ptr);
}

t_data	as_init(void)
{
	t_data	data;

	data.head = NULL;
	ft_memset(data.table, 0, (OPEN_MAX + 1) * sizeof(int8_t));
	return (data);
}

int	as_flush_data(t_data *data)
{
	as_flush_mem(&data->head);
	as_close_all(*data);
	return (0);
}

void	as_error_exit(t_data *data, const char *err_str)
{
	perror(err_str);
	as_flush_data(data);
	exit(EXIT_FAILURE);
}