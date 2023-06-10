# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 05:09:46 by tponutha          #+#    #+#              #
#    Updated: 2023/06/11 05:09:38 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of Program
NAME		= fractol
ifeq ($(uname), Linux)
	MLX_DIR = $(LINUX_DIR)
	MLX_FLAG = $(LINUX_FLAG)
else
	MLX_DIR = $(MAC_DIR)
	MLX_FLAG = $(MAC_FLAG)
endif

# Compiler Porperties
CC		= cc
CFLAG	= -Wall -Werror -Wextra -O3 -I$(MLX_DIR)
DFLAG	= -fsanitize=address
RM		= rm -f

# MLX Porperties
MAC_DIR		= ./mlx_mac
MAC_FLAG	= -framework OpenGL -framework AppKit
LINUX_DIR	= ./mlx_linux
LINUX_FLAG	= -L/usr/lib -lXext -lz -lX11

MLX		= make -C $(MLX_DIR)
LIBFLAG	= -L$(MLX_DIR) -lmlx -lm

# Source Code
MAN_DIR		= ./
MAN_HEADER	= ./fractol.h
MAN_FILE	= fractol.c
MAN_SRCS	= $(addprefix $(MAN_DIR), $(MAN_FILE))
MAN_OBJS	= $(MAN_SRCS:.c=.o)

# Compile Object Files
.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Main Rules
$(NAME):	$(MAN_OBJS)
	$(MLX)
	$(CC) $(CFLAG) $(MAN_OBJS) $(LIBFLAG) $(MLX_FLAG) -o $(NAME)

all:	$(NAME)

clean:
	$(MLX) clean
	$(RM) $(MAN_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

# ETC Rules
norm:
	@norminette -R CheckForbiddenSourceHeader $(MAN_SRCS) $(MAN_HEADER)

debug_man:	$(MAN_OBJS)
	$(MLX)
	$(CC) $(CFLAG) $(DFLAG) $(MAN_OBJS) $(LIBFLAG) $(MLXFLAG) -o $(NAME)
