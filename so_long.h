/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:55:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/28 23:14:23 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

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
	int				img_width;
	int				img_height;
	char			**map;
	int				width;
	int				height;
	int				p_pos[2];
	int				e_pos[2];
	int				player_no;
	int				exit_no;
	int				col_point;
	int				is_surround;
	int				move;
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
void	sl_image_free(t_data *data);
void	sl_init_solong(t_data *data, char *title);

/*		*/
int		sl_key(int keycode, t_data *data);
int		sl_red(t_data *data);

/*		*/
int		sl_open(char *path, int option);
void	sl_print_error(char *second);
void	sl_exit(t_list **head, int status);
void	sl_drestroy_image(void *mlx, void *image);
void	*sl_image(t_data *data, char *path, int *width, int *height);

#endif