/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:55:04 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/22 11:52:37 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	void	*img2;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	unsigned int	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel >> 3));
// 	*dst = color;
// }

// void	draw_square(t_data *data, int x, int y, int height, int width)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < width)
// 	{
// 		j = 0;
// 		while (j < height)
// 		{
// 			my_mlx_pixel_put(data, x + i, y + j, 0x00FF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	ps_close_windows(int keycode, t_vars *vars)
// {
// 	if (keycode == 53)
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_vars	vars;
// 	char	*relative_path = "./textures/Exit.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	vars.mlx = mlx;
// 	vars.win = mlx_win;
// 	mlx_hook(vars.win, 2, 1L<<0, ps_close_windows, &vars);
// 	img.img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img2, 0, 0);
// 	mlx_loop(mlx);
// }

/*
SO_LONG INSTRUCTION
1.) check file extension
2.) do ft_lseek?
3.) read whole file
4.) split by \n
5.) check if it's actually retangular
6.) check for illegal charactor
7.) check if map surrounded by wall
8.) do flood fill, and check if there is any Point left
9.) 
*/

int	main(int ac, char **av)
{
	if (ac != 2)
		return (EXIT_SUCCESS);
	
}