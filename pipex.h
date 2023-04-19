/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:37:50 by tponutha          #+#    #+#             */
/*   Updated: 2023/04/19 07:20:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "astable.h"
# include <sys/wait.h>
# include <errno.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_errno_logic(int err, t_data *data, const char *str);

#endif