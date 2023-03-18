/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:53:41 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/18 16:22:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <limits.h>
# include "listmem.h"

# define TRUE 1
# define FALSE 0

// Define Variables
# define SWAP_A 1
# define SWAP_B 2
# define SWAP_AB 3
# define PUSH_A 4
# define PUSH_B 5
# define ROTATE_A 6
# define ROTATE_B 7
# define ROTATE_AB 8
# define REV_ROTATE_A 9
# define REV_ROTATE_B 10
# define REV_ROTATE_AB 11

// Define String
# define STR_SWAP_A "sa\n"
# define STR_SWAP_B "sb\n"
# define STR_SWAP_AB "ss\n"
# define STR_PUSH_A "pa\n"
# define STR_PUSH_B "pb\n"
# define STR_ROTATE_A "ra\n"
# define STR_ROTATE_B "rb\n"
# define STR_ROTATE_AB  "rr\n"
# define STR_REV_ROTATE_A "rra\n"
# define STR_REV_ROTATE_B "rrb\n"
# define STR_REV_ROTATE_AB "rrr\n"

// Define Struct
typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// stack_work.c
t_stack	*stack_build(int *arr, int size, t_listmem **head);
t_stack	*stack_pop(t_stack **stack);
void	stack_push(t_stack **stack, t_stack *node);
void	stack_pop_push(t_stack **dest, t_stack **src);

// stack_command.c
void	stack_swap(t_stack **stack);
void	stack_pop_push(t_stack **dest, t_stack **src);
void	stack_rotate(t_stack **stack);
void	stack_reverse_rotate(t_stack **stack);
void	stack_exit(t_listmem **head);

// stack_split.c
char	**ft_split(char const *s, char c, t_listmem **spt);

// stack_atoi.c
long	stack_atoi(char *str);

// stack_duplicate.c
int		stack_isduplicate(int *arr, int size, t_listmem **head);

// stack_args.c
int	*stack_check_n_return(int ac, int *len, char **av, t_listmem **head);

// stack_utility.c
void	*ft_memmove(void *dst, const void *src, size_t byte);
size_t	ft_strclen(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strncat(char *dst, const char *src, size_t size);

// stack_format.c
//t_stack	*stack_check_array(int ac, char **av, t_listmem **head);

#endif