# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:58:59 by tponutha          #+#    #+#              #
#    Updated: 2023/07/28 03:44:37 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME	= philo

# Compiler Properties 
CC		= cc
CFLAG	= -Wall -Werror -Wextra -std=c17 -g #-fsanitize=address,undefined
RM		= rm -f

# File
MAN_DIR		= ./
MAN_HEADER	= ./philo.h
MAN_FILE	= philo.c ft_utils.c ph_sim.c ph_act.c ph_mutex.c
MAN_SRCS	= $(addprefix $(MAN_DIR), $(MAN_FILE))
MAN_OBJS	= $(MAN_SRCS:.c=.o)

# Compiler Process
.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(MAN_OBJS)
	$(CC) $(CFLAG) -lpthread $(MAN_OBJS) -o $(NAME)

clean:
	$(RM) $(MAN_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(MAN_SRCS) $(MAN_HEADER)