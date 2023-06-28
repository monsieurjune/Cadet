/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:51:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/28 21:03:53 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_image_free(t_data *data)
{
	sl_drestroy_image(data->mlx, data->player);
	sl_drestroy_image(data->mlx, data->floor);
	sl_drestroy_image(data->mlx, data->wall);
	sl_drestroy_image(data->mlx, data->exit);
	sl_drestroy_image(data->mlx, data->collect);
	sl_exit(&data->head, EXIT_SUCCESS);
}

static void	sb_create_mlx(t_data *data)
{
	int	size[2];

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		sl_image_free(data);
	data->player = sl_image(data, PLAYER_PATH, &size[0], &size[1]);
	data->floor = sl_image(data, FLOOR_PATH, &size[0], &size[1]);
	data->wall = sl_image(data, WALL_PATH, &size[0], &size[1]);
	data->collect = sl_image(data, COLLECT_PATH, &size[0], &size[1]);
	data->exit = sl_image(data, EXIT_PATH, &size[0], &size[1]);
	if (data->player && data->floor && data->wall \
		&& data->collect && data->exit)
	{
		data->img_width = size[0];
		data->img_height = size[1];
	}
	else
		sl_image_free(data);
}

static void	sb_put_image(t_data *data, int x, int y)
{
	void	*mlx;
	void	*window;
	int		off_x;
	int		off_y;

	mlx = data->mlx;
	window = data->window;
	off_x = x * data->img_width;
	off_y = y * data->img_height;
	if (data->map[y][x] == WALL)
		mlx_put_image_to_window(mlx, window, data->wall, off_x, off_y);
	else if (data->map[y][x] == PLAYER)
		mlx_put_image_to_window(mlx, window, data->player, off_x, off_y);
	else if (data->map[y][x] == EXIT)
		mlx_put_image_to_window(mlx, window, data->exit, off_x, off_y);
	else if (data->map[y][x] == FLOOR)
		mlx_put_image_to_window(mlx, window, data->floor, off_x, off_y);
	else if (data->map[y][x] == COLLECT)
		mlx_put_image_to_window(mlx, window, data->collect, off_x, off_y);
}

static void	sb_render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			sb_put_image(data, x, y);
			x++;
		}
		y++;
	}
}

void	sl_init_solong(t_data *data, char *title)
{
	int	width;
	int	height;

	sb_create_mlx(data);
	width = data->img_width * data->width;
	height = data->img_height * data->height;
	data->window = mlx_new_window(data->mlx, width, height, title);
	if (data->window == NULL)
		sl_image_free(data);
	sb_render_map(data);
}
