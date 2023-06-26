/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:09:27 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 00:35:19 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sb_isnt_x_wall(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		if (data->map[0][x] != WALL)
			return (sl_print_error("Map isn't surround by wall"), 1);
		x++;
	}
	x = 0;
	while (x < data->width)
	{
		if (data->map[data->height - 1][x] != WALL)
			return (sl_print_error("Map isn't surround by wall"), 1);
		x++;
	}
	return (0);
}

static int	sb_isnt_y_wall(t_data *data)
{
	int	y;
	
	y = 0;
	while (y < data->height)
	{
		if (data->map[y][0] != WALL)
			return (sl_print_error("Map isn't surround by wall"), 1);
		y++;
	}
	y = 0;
	while (y < data->height)
	{
		if (data->map[y][data->width - 1] != WALL)
			return (sl_print_error("Map isn't surround by wall"), 1);
		y++;
	}
	return (0);
}

static int	sb_count_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == PLAYER)
				data->player_no += 1;
			else if (data->map[y][x] == EXIT)
				data->exit_no += 1;
			else if (data->map[y][x] == COLLECT)
				data->col_point += 1;
			x++;
		}
		y++;
	}
	return (data->col_point < 1 || data->exit_no != 1 || data->player_no != 1);
}

int	sl_mapcheck(t_data *data)
{
	data->col_point = 0;
	data->exit_no = 0;
	data->player_no = 0;
	if (sb_isnt_x_wall(data))
		return (1);
	if (sb_isnt_y_wall(data))
		return (1);
	if (sb_count_map(data))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (data->col_point < 1)
			ft_putstr_fd("Map must has >=1 Collectable\n", STDERR_FILENO);
		if (data->exit_no != 1)
			ft_putstr_fd("Map must has 1 Exit", STDERR_FILENO);
		if (data->player_no != 1)
			ft_putstr_fd("Map must has 1 Player", STDERR_FILENO);
		return (1);
	}
	return (0);
}