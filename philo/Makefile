# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:58:59 by tponutha          #+#    #+#              #
#    Updated: 2023/07/08 15:54:48 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME	= philo

# Compiler Properties
CC		= cc
CFLAG	= -Wall -Werror -Wextra -lpthread -g
RM		= rm -f

# File
MAN_DIR		= ./
MAN_HEADER	= ./philo.h
MAN_FILE	= philo.c
MAN_SRCS	= $(addprefix $(DIRC), $(MAN))
MAN_OBJS	= $(MAN_SRCS:.c=.o)

# Compiler Process
.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(MAN_OBJS)
	$(CC) $(CFLAG) -o $(NAME)

clean:
	$(RM) $(MAN_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(MAN_SRCS) $(MAN_HEADER)