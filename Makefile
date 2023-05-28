# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 03:48:25 by tponutha          #+#    #+#              #
#    Updated: 2023/05/28 17:22:16 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main properties
NAME		= pipex
UNAME		= $(shell uname -s)

# Complier & shell thing
CC		= cc
RM		= rm -f
CFLAG	= -Wall -Werror -Wextra
DFLAG	= -fsanitize=address

# Listmem Directory
MEM_DIR		= ./
NEM_HEADER	= listmem.h
MEM_FILE	= listfree.c listmem.c
MEM_SRCS	= $(addprefix $(MEM_DIR), $(MEM_FILE))

# Libft Directory
LIBFT_DIR		= ./
LIBFT_HEADER	= libft.h
LIBFT_FILE		= ft_gnl.c ft_gnl_utils.c ft_split_cmd.c
LIBFT_SRCS		= $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

# Pipex Directory
PIPEX_DIR		= ./
PIPEX_HEADER	= pipex.h
PIPEX_FILE		= pipex.c
PIPEX_SRCS		= $(addprefix $(PIPEX_DIR), $(PIPEX_FILE))

# Complie Process
SRCS		= $(MEM_SRCS) $(LIBFT_SRCS) $(PIPEX_SRCS)
HEADER		= $(MEM_HEADER) $(LIBFT_HEADER) $(PIPEX_HEADER)
OBJS		= $(SRCS:.c=.o)
INCS		= $(addprefix -I, $(HEADER))

.c.o:
	$(CC) $(CFLAG) $(INCS) -c $< -o $(<:.c=.o)

# failsafe
.PHONY: all clean fclean re norm

# MAIN RULES
$(NAME):	$(OBJ)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

bonus:	all

# ETC RULES
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) $(HEADER)

debug:	fclean $(OBJS)
	$(CC) $(CFLAG) $(DFLAG) $(OBJS) -o $(NAME)
