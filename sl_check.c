/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:09:27 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 17:00:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**sb_copy_map(char **box, int height, t_list **head)
{
	char	**copy;
	int		y;

	copy = ft_malloc(sizeof(char *), height + 1, head);
	if (copy == NULL)
		return (NULL);
	y = 0;
	while (box[y] != NULL)
	{
		copy[y] = ft_strdup(box[y], head);
		if (copy[y] == NULL)
			return (ft_flush(head), NULL);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	sl_copy_data(t_data data, t_data *copy)
{
	copy->width = data.width;
	copy->height = data.height;
	copy->is_surround = data.is_surround;
	copy->p_pos[0] = data.p_pos[0];
	copy->p_pos[1] = data.p_pos[1];
	copy->p_pos[0] = data.p_pos[0];
	copy->p_pos[1] = data.p_pos[1];
	copy->exit_no = data.exit_no;
	copy->player_no = data.player_no;
	copy->col_point = data.col_point;
	copy->head = NULL;
	copy->map = sb_copy_map(data.map, data.height, &copy->head);
	return (copy->map == NULL);
}

void	sl_floodfill(t_data *copy, int x, int y)
{
	if ((x == 0 || x == copy->width - 1 || y == 0 || y == copy->height - 1) \
		&& copy->map[y][x] != WALL)
	{
		copy->is_surround = 0;
		return ;
	}
	else if (copy->map[y][x] == WALL)
		return ;
	else if (copy->map[y][x] == COLLECT)
		copy->col_point -= 1;
	else if (copy->map[y][x] == EXIT)
		copy->exit_no -= 1;
	else if (copy->map[y][x] == PLAYER)
		copy->player_no -= 1;
	copy->map[y][x] = WALL;
	sl_floodfill(copy, x - 1, y);
	sl_floodfill(copy, x + 1, y);
	sl_floodfill(copy, x, y - 1);
	sl_floodfill(copy, x, y + 1);
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
			else if (ft_strchr(LEGAL, data->map[y][x]) == NULL)
				return (1);
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
	data->is_surround = 1;
	if (sb_count_map(data))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (data->col_point < 1)
			ft_putstr_fd("Map must has >=1 Collectable\n", STDERR_FILENO);
		else if (data->exit_no != 1)
			ft_putstr_fd("Map must has 1 Exit\n", STDERR_FILENO);
		else if (data->player_no != 1)
			ft_putstr_fd("Map must has 1 Player\n", STDERR_FILENO);
		else
			ft_putstr_fd("Map contain Illegal charactor(s)\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}