# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 05:09:46 by tponutha          #+#    #+#              #
#    Updated: 2023/06/03 17:48:21 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of Program
NAME	= fractol
MLX_DIR	= ./mlx_mac

# Compiler Porperties
CC		= cc
CFLAG	= -Wall -Werror -Wextra -I$(MLX_DIR)
DFLAG	= -fsanitize=address
RM		= rm -f

# MLX Porperties
MLXFLAG	= -framework OpenGL -framework AppKit
LIBFLAG	= -L$(MLX_DIR) -lmlx -lm
MLX		= make -C $(MLX_DIR)


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
	$(CC) $(CFLAG) $(MAN_OBJS) $(LIBFLAG) $(MLXFLAG) -o $(NAME)

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
