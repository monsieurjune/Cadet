# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 05:09:46 by tponutha          #+#    #+#              #
#    Updated: 2023/06/27 17:36:08 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of Program
NAME		= so_long

# Compiler Porperties
CC		= cc
CFLAG	= -Wall -Werror -Wextra -O3 -g -fsanitize=address,undefined
RM		= rm -f

# MLX Porperties
LIBFT_DIR	= ./libft
MLX_DIR		= ./mlx
MLX_FLAG	= -framework OpenGL -framework AppKit
MLX			= make -C $(MLX_DIR)
LIBFT		= make -C $(LIBFT_DIR)
LIBFLAG		= -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lm -lft

# Source Code
MAN_DIR		= ./
MAN_HEADER	= ./so_long.h
MAN_FILE	= so_long.c sl_file.c sl_flood.c sl_utils.c sl_check.c
MAN_SRCS	= $(addprefix $(MAN_DIR), $(MAN_FILE))
MAN_OBJS	= $(MAN_SRCS:.c=.o)

# Compile Object Files
.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Main Rules
$(NAME):	$(MAN_OBJS)
	$(MLX)
	$(LIBFT)
	$(CC) $(CFLAG) $(MAN_OBJS) $(LIBFLAG) $(MLX_FLAG) -o $(NAME)

all:	$(NAME)

clean:
	$(MLX) clean
	$(LIBFT) clean
	$(RM) $(MAN_OBJS)

fclean:	clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re:	fclean all

# ETC Rules
norm:
	@norminette -R CheckForbiddenSourceHeader $(MAN_SRCS) $(MAN_HEADER)

debug_san:	$(MAN_OBJS)
	$(MLX)
	$(CC) $(CFLAG) -g -fsanitize=address $(MAN_OBJS) $(LIBFLAG) $(MLXFLAG) -o $(NAME)

debug_leak:	$(MAN_OBJS)
	$(MLX)
	$(CC) $(CFLAG) -g $(MAN_OBJS) $(LIBFLAG) $(MLXFLAG) -o $(NAME)
