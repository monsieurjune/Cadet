/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:35:46 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/05 20:29:48 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "stack.h"
# include <stdio.h>

// ps_pipeline.c
void	ps_pipeline(int cmd, t_stack *a, t_stack *b);
void	ps_putback_to_a(t_stack *a, t_stack *b);

// ps_quicksort.c
void	ps_quicksort(t_stack *a, t_stack *b, int high);

// ps_utility.c
int     ps_bottom_index(t_stack a, int bottom);
int	    ps_find_less(t_stack a, int pivot);
long	diff_abs(long a, long b);
void	ps_a_to_b(t_stack *a, t_stack *b, int val);


#endif