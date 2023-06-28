/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:07:12 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/28 21:04:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sb_render_move(t_data *data, int x0, int y0)
{
	void	*mlx;
	void	*win;
	int		off_x;
	int		off_y;

	mlx = data->mlx;
	win = data->window;
	off_x = data->p_pos[1] * data->img_width;
	off_y = data->p_pos[0] * data->img_height;
	mlx_put_image_to_window(mlx, win, data->player, off_x, off_y);
	off_x = x0 * data->img_width;
	off_y = y0 * data->img_height;
	if (data->map[y0][x0] == FLOOR)
		mlx_put_image_to_window(mlx, win, data->floor, off_x, off_y);
	else if (data->map[y0][x0] == EXIT)
		mlx_put_image_to_window(mlx, win, data->exit, off_x, off_y);
}

static void	sb_check_move(t_data *data, int x1, int y1)
{
	int	x0;
	int	y0;

	x0 = data->p_pos[1];
	y0 = data->p_pos[0];
	if (data->map[y1][x1] == WALL)
		return ;
	if (data->map[y1][x1] == COLLECT)
		data->col_point -= 1;
	data->map[y0][x0] = FLOOR;
	data->p_pos[0] = y1;
	data->p_pos[1] = x1;
	data->map[y1][x1] = PLAYER;
	if (x1 != data->e_pos[1] || y1 != data->e_pos[0])
		data->map[data->e_pos[0]][data->e_pos[1]] = EXIT;
	data->move += 1;
	ft_putstr_fd("MOVE : ", STDOUT_FILENO);
	ft_putnbr_fd(data->move, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	sb_render_move(data, x0, y0);
}

static void	sb_move_player(t_data *data, int keycode)
{
	if (keycode == UP || keycode == W)
		sb_check_move(data, data->p_pos[1], data->p_pos[0] - 1);
	else if (keycode == DOWN || keycode == S)
		sb_check_move(data, data->p_pos[1], data->p_pos[0] + 1);
	else if (keycode == LEFT || keycode == A)
		sb_check_move(data, data->p_pos[1] - 1, data->p_pos[0]);
	else if (keycode == RIGHT || keycode == D)
		sb_check_move(data, data->p_pos[1] + 1, data->p_pos[0]);
	if (data->col_point == 0 && data->e_pos[0] == data->p_pos[0] \
		&& data->e_pos[1] == data->p_pos[1])
	{
		mlx_destroy_image(data->mlx, data->window);
		sl_image_free(data);
	}
}

int	sl_key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		sl_image_free(data);
	}
	else
		sb_move_player(data, keycode);
	return (0);
}

int	sl_red(int keycode, t_data *data)
{
	(void)keycode;
	sl_image_free(data);
	return (0);
}
