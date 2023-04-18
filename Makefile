# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 03:48:25 by tponutha          #+#    #+#              #
#    Updated: 2023/04/19 05:02:29 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main properties
NAME		= push_swap

# Complier & shell thing
CC		= cc
RM		= rm -f
CFLAG	= -Wall -Werror -Wextra

# Listmem Directory


# Complie Process
SRCS	= $(MAIN_SRCS) $(MEM_SRCS) $(STACK_SRCS)
OBJ		= $(SRCS:.c=.o)
IFLAG	= -I$(MAIN_DIR)
.c.o:
	$(COM) $(CFLAG) -c $(IFLAG) $< -o $(<:.c=.o)

# failsafe
.PHONY: all clean fclean re norm

# MAIN RULES
$(NAME):	$(OBJ) Makefile
	$(COM) $(CFLAG) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

# ETC RULES
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)