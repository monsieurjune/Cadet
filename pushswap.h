/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:35:46 by tponutha          #+#    #+#             */
/*   Updated: 2023/03/24 21:44:26 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "stack.h"

// ps_pipeline.c
void	ps_pipeline(int cmd, t_stack *a, t_stack *b);

// ps_quicksort.c
void	ps_quicksort(t_stack *a, t_stack *b);

#endif