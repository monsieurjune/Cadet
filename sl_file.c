/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:26:57 by tponutha          #+#    #+#             */
/*   Updated: 2023/06/27 16:51:23 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// box = nl + 1(end-line) + 1(null)

static int	sb_count_nl(char *path)
{
	char	*cmp;
	char	buff;
	int		nl;
	int		n;
	int		fd;

	fd = sl_open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	cmp = ft_strchr(ft_strrchr(path, '/'), '.');
	if (ft_strncmp(cmp, ".ber", sizeof(".ber") - 1) != 0)
		return (sl_print_error("Not a '.ber' files"), close(fd), -1);
	nl = 0;
	n = read(fd, &buff, 1);
	while (n != 0 && n != -1)
	{
		nl += (buff == '\n');
		n = read(fd, &buff, 1);
	}
	close(fd);
	if (n == -1)
		return (-1);
	return (nl);
}

static char	**sb_get_box(char *path, t_list **head, int *len)
{
	int		i;
	int		fd;
	char	**box;

	*len = sb_count_nl(path) + 1;
	if (*len <= 0)
		return (NULL);
	box = ft_malloc(sizeof(char *), *len + 1, head);
	if (box == NULL)
		return (NULL);
	fd = sl_open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < *len)
	{
		box[i] = get_next_line(fd, head);
		i++;
	}
	close(fd);
	box[i] = NULL;
	return (box);
}

// check if it's rectangular
// check if width >= 3 && width > 3 if height == 3
// check if height >= 3 && height > 3 if width == 3
// i = height
// ref = width

static int	sb_is_not_rectangular(char **box, int nlen, t_data *data)
{
	int	len;
	int	ref;
	int	i;

	i = 1;
	ref = ft_strclen(box[0], '\n');
	box[0][ref] = 0;
	while (box[i] != NULL)
	{
		len = ft_strclen(box[i], '\n');
		box[i][len] = 0;
		if (ref != len)
			return (sl_print_error("Map isn't rectangular"), 1);
		i++;
	}
	data->width = ref;
	data->height = i;
	if (i != nlen)
		sl_print_error("Map isn't rectangular");
	return (i != nlen);
}

static void	sb_find_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == EXIT)
			{
				data->e_pos[0] = y;
				data->e_pos[1] = x;
			}
			if (data->map[y][x] == PLAYER)
			{
				data->p_pos[0] = y;
				data->p_pos[1] = x;
			}
			x++;
		}
		y++;
	}
}

// void	print_map(char **box)
// {
// 	int	i = 0;
// 	while (box[i] != NULL)
// 	{
// 		printf("%s", box[i]);
// 		i++;
// 	}
// 	// printf("%s", box[0]);
// 	// printf("%s", box[1]);
// 	// printf("%s", box[2]);
// 	// printf("%s", box[3]);
// 	// printf("%s", box[4]);
// 	// printf("%s", box[5]);
// }

void	sl_mapping(char *path, t_data *data)
{
	t_data	copy;
	int		nlen;

	data->head = NULL;
	data->map = sb_get_box(path, &data->head, &nlen);
	if (data->map == NULL)
		sl_exit(&data->head, EXIT_SUCCESS);
	if (sb_is_not_rectangular(data->map, nlen, data))
		sl_exit(&data->head, EXIT_SUCCESS);
	if (sl_mapcheck(data))
		sl_exit(&data->head, EXIT_SUCCESS);
	sb_find_position(data);
	if (sl_copy_data(*data, &copy))
		sl_exit(&data->head, EXIT_SUCCESS);
	sl_floodfill(&copy, copy.p_pos[1], copy.p_pos[0]);
	ft_flush(&copy.head);
	if (copy.is_surround == 0)
		sl_print_error("Map isn't surrounded by wall");
	else if (copy.exit_no != 0 || copy.col_point != 0)
		sl_print_error("Please, no one can play this map (floodfill)");
	if (copy.is_surround == 0 || copy.exit_no != 0 || copy.col_point != 0)
		sl_exit(&data->head, EXIT_SUCCESS);
}

/*
#include <stdio.h>
int main()
{
	t_list *head;
	head = NULL;
	int len = sb_count_nl("./maps/map1.ber", &head);
	printf("%d\n", len);
}
*/