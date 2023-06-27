/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:55:04 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 13:40:02 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	void	*img2;
// 	void	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_vars;

// int	ps_close_windows(int keycode, t_vars *vars)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, 1100, 110);
// 		// sleep(10);
// 		// mlx_destroy_window(vars->mlx, vars->win);
// 		// exit(0);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_vars	vars;
// 	char	*relative_path = "./textures/Exit.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	// vars.img = mlx_new_image(mlx, 1920, 1080);
// 	// vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
// 	// 							&vars.endian);
// 	vars.mlx = mlx;
// 	vars.win = mlx_win;
// 	mlx_hook(vars.win, 2, 1L<<0, ps_close_windows, &vars);
// 	vars.img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	// mlx_put_image_to_window(mlx, mlx_win, vars.img, 0, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, vars.img2, 0, 0);
// 	// mlx_put_image_to_window(mlx, mlx_win, vars.img2, 110, 110);
// 	mlx_loop(mlx);
// 	return (0);
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
	t_data	data;

	if (ac != 2)
		return (EXIT_SUCCESS);
	sl_mapping(av[1], &data);
	ft_flush(&data.head);
	return (0);
}