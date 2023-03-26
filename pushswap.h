/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:35:46 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/25 19:50:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "stack.h"

// ps_pipeline.c
void	ps_pipeline(int cmd, t_stack *a, t_stack *b);
void	ps_putback_to_a(t_stack *a, t_stack *b);

// ps_quicksort.c
void	ps_quicksort(t_stack *a, t_stack *b, t_node *low, t_node *high);

// ps_node.c
int	    ps_node_depth(t_stack stack, t_node *node);
int	    ps_node_search(t_node *top, t_node *find);
void	ps_a_to_b(t_stack *a, t_stack *b, t_node *node);


#endif