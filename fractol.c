/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 05:43:02 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/10 20:48:36 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int height, int width)
{
	int i = 0;
	int j = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			my_mlx_pixel_put(data, x + i, y + j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ps_close_windows(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.mlx = mlx;
	vars.win = mlx_win;
	mlx_hook(vars.win, 2, 1L<<0, ps_close_windows, &vars);
	draw_square(&img, 0, 0, 1000, 1000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
*/