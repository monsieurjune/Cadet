/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:57:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/16 16:37:22 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	sb_int_transform(char **box, );

// size = all_argv_len + (ac - 1) + 1
// size = all_argv_len + ac

static size_t	sb_argvlen(int ac, char **av)
{
	size_t	size;
	int		i;

	i = 1;
	size = 0;
	while (i < ac)
	{
		size += ft_strclen(av[i], 0);
		i++;
	}
	return (size + ac);
}

/* Transform av to single string
-> str[n] = str[n-1] + av[n] + ' '
-> alloc once then copy later
*/

static char	*sb_str_transform(int ac, char **av, t_listmem **spt)
{
	char	*str;
	int		i;
	size_t	size;

	i = 1;
	size = sb_argvlen(ac, av);
	str = lm_malloc(sizeof(char), size, spt);
	if (str == NULL)
		stack_exit(spt);
	while (i < ac)
	{
		(void)ft_strlcat(str, av[i], size);
		(void)ft_strlcat(str, " ", size);
		i++;
	}
	return (str);
}

/* check if args are in correct
- correct -> return int array
- not correct -> call stack_exit
- allocation fail -> call stack_exit 
*/

int	*stack_check_n_return(int ac, char **av)
{
	t_listmem	*spt;
	char		**box;
	char		*str;
	int			*arr;

	spt = NULL;
	str = sb_str_transform(ac, av, &spt);
	box = ft_split(str, ' ', &spt);
	if (box == NULL)
		stack_exit(&spt);
	arr = sb_int_transform();
}