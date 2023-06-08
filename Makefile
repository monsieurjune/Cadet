# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 14:12:15 by tponutha          #+#    #+#              #
#    Updated: 2023/06/09 04:21:46 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of Program
NAME		= pipex

# Compiler properties
CC		= cc
CFLAG	= -Wall -Werror -Wextra
DFLAG	= -g
FFLAG	= -fsanitize=address
RM		= rm -f

# Lib file
LIBDIR		= ./
LIBFILE		= ft_gnl_utils.c ft_split_cmd.c ft_strjoin.c ft_strnstr.c \
				listfree.c listmem.c
LIBHEADER	= ./libft.h
LIBSRCS		= $(addprefix $(LIBDIR), $(LIBFILE))
LIBOBJS		= $(LIBSRCS:.c=.o)

# Common file
COMDIR		= ./
COMFILE		= px_perror.c px_process.c px_info.c px_stream.c px_ultra_split.c \
				px_exit.c
COMHEADER	= ./pipex.h
COMSRCS		= $(addprefix $(COMDIR), $(COMFILE))
COMOBJS		= $(COMSRCS:.c=.o)

# Mandatory
MANDIR		= ./
MANFILE		= pipex.c
MANSRCS		= $(addprefix $(MANDIR), $(MANFILE))
MANOBJS		= $(MANSRCS:.c=.o)

# Bonus
BONUSDIR	= ./
BONUSFILE	= pipex_bonus.c ft_gnl_bonus.c px_hd_bonus.c
BONUSHEADER	= ./pipex_bonus.h
BONUSSRCS	= $(addprefix $(BONUSDIR), $(BONUSFILE))
BONUSOBJS	= $(BONUSSRCS:.c=.o)

# Compile Process
MOBJS	= $(LIBOBJS) $(COMOBJS) $(MANOBJS)
BOBJS	= $(LIBOBJS) $(COMOBJS) $(BONUSOBJS)
OBJS	= $(LIBOBJS) $(COMOBJS) $(MANOBJS) $(BONUSOBJS)

ifdef WITH_BONUS
    OBJ = $(BOBJS)
else
    OBJ = $(MOBJS)
endif
.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Main Rule
.PHONY:	all clean fclean re bonus

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus:
	@make WITH_BONUS=1 $(NAME)