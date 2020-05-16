# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 11:56:52 by mskinner          #+#    #+#              #
#    Updated: 2020/03/12 17:54:07 by mskinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra

SRC =	ft_isalnum.c	ft_isprint.c	ft_memcmp.c		ft_putchar_fd.c	ft_split.c		ft_strlcat.c	ft_strncmp.c	ft_substr.c	\
		ft_atoi.c		ft_isalpha.c	ft_itoa.c		ft_memcpy.c		ft_putendl_fd.c	ft_strchr.c		ft_strlcpy.c	ft_strnstr.c \
		ft_tolower.c	ft_bzero.c		ft_isascii.c	ft_memccpy.c	ft_memmove.c	ft_putnbr_fd.c	ft_strdup.c		ft_strlen.c	\
		ft_strrchr.c	ft_toupper.c	ft_calloc.c		ft_isdigit.c	ft_memchr.c		ft_memset.c		ft_putstr_fd.c	ft_strjoin.c \
		ft_strmapi.c	ft_strtrim.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	ft_lstdelone.c	ft_lstiter.c	ft_lstlast.c \
			ft_lstmap.c			ft_lstnew.c			ft_lstsize.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@
	
%.o: %.c $(HEADER)
	@gcc $(FLAG) -c $< -I $(HEADER) -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	@ar rcs $(NAME) $^
	@ranlib $(NAME)

.PHONY: all clean fclean re bonus
