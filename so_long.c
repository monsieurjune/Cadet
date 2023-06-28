/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:55:04 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/28 21:03:05 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	sl_init_solong(&data, "so_long");
	mlx_hook(data.window, 2, 1L << 0, sl_key, &data);
	mlx_hook(data.window, 17, 1L << 17, sl_red, &data);
	mlx_loop(data.mlx);
	return (0);
}
