# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 22:05:44 by tponutha          #+#    #+#              #
#    Updated: 2023/07/02 17:11:24 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRC = ./

NAME = libft.a

MAN = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c \
	ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_striteri.c\
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c \
	ft_tolower.c ft_toupper.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_malloc.c ft_flush.c ft_free.c ft_strclen.c ft_strndup.c ft_strcdup.c \
	get_next_line.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

COM		= cc

FLAG	= -Wall -Werror -Wextra -O3# -g -fsanitize=address,undefined

# ifdef DEBUG
#     FLAG += $(DFLAG)
# endif

RM		= rm -f

SRCMAN = $(addprefix $(DIRC), $(MAN))

SRCBONUS = $(addprefix $(DIRC), $(BONUS))

OBJMAN = $(SRCMAN:.c=.o)

OBJBONUS = $(OBJMAN) $(SRCBONUS:.c=.o)

.c.o:
	$(COM) $(FLAG) -c $< -o $(<:.c=.o)

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJBONUS)
	ar rcs $(NAME) $(OBJBONUS)

clean:
	@$(RM) $(OBJBONUS)

fclean:	clean
	@$(RM) $(NAME)

bonus:	all

re:	fclean all
