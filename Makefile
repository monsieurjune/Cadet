# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 03:48:25 by tponutha          #+#    #+#              #
#    Updated: 2023/04/19 06:31:30 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main properties
NAME		= push_swap

# Complier & shell thing
CC		= cc
RM		= rm -f
CFLAG	= -Wall -Werror -Wextra
ifeq ($(UNAME), Linux)
	LIB = -libbsd
endif

# Listmem Directory
MEM_DIR		= ./
NEM_HEADER	= astable.h
MEM_FILE	= astable.c as_malloc.c as_free.c as_file.c
MEM_SRCS	= $(addprefix $(MEM_DIR), $(MEM_FILE))

# Complie Process
SRCS	= $(MEM_SRCS)
INC		= $(MEM_HEADER)
OBJ		= $(SRCS:.c=.o)
IFLAG	= -I$(MEM_DIR)
UNAME	= $(shell uname -s)

.c.o:
	$(CC) $(CFLAG) $(LIB) -c $(IFLAG) $< -o $(<:.c=.o)

# failsafe
.PHONY: all clean fclean re norm

# MAIN RULES
$(NAME):	$(OBJ)
	$(COM) $(CFLAG) $(LIB) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

# ETC RULES
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) 