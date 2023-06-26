/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:55:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 00:16:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx_mac/mlx.h"
# include <fcntl.h>
# include "./libft/libft.h"
#include <stdio.h>

# ifndef ESC
#  define ESC 53
# endif

# ifndef W
#  define W 13
# endif

# ifndef UP
#  define UP 126
# endif

# ifndef A
#  define A 0
# endif

# ifndef LEFT
#  define LEFT 123
# endif

# ifndef S
#  define S 1
# endif

# ifndef DOWN
#  define DOWN 125
# endif

# ifndef D
#  define D 2
# endif

# ifndef RIGHT
#  define RIGHT 124
# endif

# ifndef LEGAL
#  define LEGAL "01CPE"
# endif

# ifndef WALL
#  define WALL '1'
# endif

# ifndef WALL_PATH
#  define WALL_PATH "./textures/Wall.xpm" 
# endif

# ifndef FLOOR
#  define FLOOR '0'
# endif

# ifndef FLOOR_PATH
#  define FLOOR_PATH "./textures/Floor.xpm"
# endif

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef PLAYER_PATH
#  define PLAYER_PATH "./textures/Player.xpm"
# endif

# ifndef COLLECT
#  define COLLECT 'C'
# endif

# ifndef COLLECT_PATH
#  define COLLECT_PATH "./textures/Collect.xpm"
# endif

# ifndef EXIT
#  define EXIT 'E'
# endif

# ifndef EXIT_PATH
#  define EXIT_PATH "./textures/Exit.xpm"
# endif

typedef struct s_data
{
	void			*mlx;
	void			*window;
	void			*player;
	void			*floor;
	void			*wall;
	void			*collect;
	void			*exit;
	char			**map;
	int				width;
	int				height;
	int				p_pos[2];
	int				e_pos[2];
	int				player_no;
	int				exit_no;
	int				col_point;
	struct s_list	*head;
}	t_data;

/*		*/
void	sl_mapping(char *path, t_data *data);

/*		*/
int		sl_mapcheck(t_data *data);

/*		*/
int		sl_copy_data(t_data data, t_data *copy);
void	sl_floodfill(t_data *copy, int x, int y);

/*		*/
int		sl_open(char *path, int option);
void	sl_print_error(char *second);
void	sl_exit(t_list **head, int status);

#endif