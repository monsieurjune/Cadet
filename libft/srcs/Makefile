# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 22:05:44 by tponutha          #+#    #+#              #
#    Updated: 2022/09/04 11:24:37 by tponutha         ###   ########.fr        #
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

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

COM = gcc

FLAG = -Wall -Werror -Wextra

RM = rm -f

SRCMAN = $(addprefix $(DIRC), $(MAN))

SRCBONUS = $(addprefix $(DIRC), $(BONUS))

OBJMAN = $(SRCMAN:.c=.o)

OBJBONUS = $(OBJMAN) $(SRCBONUS:.c=.o)

.c.o:
	$(COM) $(FLAG) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJMAN)
	ar rc $(NAME) $(OBJMAN)

clean:
	$(RM) $(OBJBONUS)

fclean:	clean
	$(RM) $(NAME)

bonus:	$(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)

re:	fclean all

.PHONY:	all clean fclean re
