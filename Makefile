# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carodrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/04 10:45:10 by carodrig          #+#    #+#              #
#    Updated: 2016/10/12 15:37:51 by carodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = carodrig.filler

FILES = main.c ft_check_filler.c ft_check_board.c ft_check_board2.c ft_algo_filler.c ft_algo_filler2.c ft_check_pos.c ft_check_pos2.c

SRC_FOLDER = sources/

OBJ_FOLDER = build/

SRCS = $(addprefix $(SRC_FOLDER),$(FILES))

OBJS = $(addprefix $(OBJ_FOLDER),$(FILES:.c=.o))

INCLUDES = -I libft/

LIBS = -L libft/ -lft -L minilibx_macos/ -lmlx -lm

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJS): $(OBJ_FOLDER)%.o : $(SRC_FOLDER)%.c
	gcc -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@

build:
	mkdir -p $(OBJ_FOLDER)
	make -C libft/ re
	make -C minilibx_macos/ re

$(NAME): build $(OBJS)
	gcc -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS) $(FRAMEWORK)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJS)
	rm -rf $(OBJ_FOLDER)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
