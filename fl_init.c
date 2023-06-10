/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:47:31 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/11 05:56:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	fl_mlx_init(char *title, int width, int height)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit(EXIT_FAILURE);
	data.window = mlx_new_window(data.mlx, width, height, title);
	if (data.window == NULL)
		exit(EXIT_FAILURE);
	return (data);
}