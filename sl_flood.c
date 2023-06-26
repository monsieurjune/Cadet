/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:14:25 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/26 22:45:56 by tponutha         ###   ########.fr       */
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
	if (copy->map[y][x] == WALL)
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