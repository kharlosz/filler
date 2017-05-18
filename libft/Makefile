# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carodrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 09:28:02 by carodrig          #+#    #+#              #
#    Updated: 2016/10/10 13:47:58 by carodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c ft_strdup.c ft_strstr.c ft_atoi.c ft_isdigit.c ft_strsub.c ft_strjoin.c ft_putchar.c ft_putstr.c ft_putnbr.c get_next_line.c

HEAD = libft.h

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
