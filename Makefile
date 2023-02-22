# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 03:48:25 by tponutha          #+#    #+#              #
#    Updated: 2023/01/26 18:31:36 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main properties
NAME		= libftprintf.a
TESTER_PATH	= ../

# Complier & shell thing
COM		= gcc
RM		= rm -f
CFLAG	= -Wall -Werror -Wextra

# Main Directory
MAIN_DIR	= ./
MAIN_FILE	= ft_printf.c ft_hex.c ft_number.c ft_string.c
MAIN_SRCS	= $(addprefix $(MAIN_DIR), $(MAIN_FILE))

# Complie Process
SRCS	= $(MAIN_SRCS)
OBJ		= $(SRCS:.c=.o)
IFLAG	= -I$(MAIN_DIR)
.c.o:
	$(COM) $(CFLAG) -c $(IFLAG) $< -o $(<:.c=.o)

# MAIN RULES
$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

all:	$(NAME)

bonus:	$(NAME)

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

# ETC RULES
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)


.PHONY: all clean fclean re bonus test clone