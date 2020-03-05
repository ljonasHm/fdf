# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljonas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 14:37:40 by ljonas            #+#    #+#              #
#    Updated: 2020/03/02 13:06:08 by ljonas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c read.c errors.c clears.c draw.c
OBJ = $(SRC:.c=.o)
LIB_DIR = libft
INC_DIR = . libft
CFLAG = -Wall -Wextra -Werror -c $(addprefix -I, $(INC_DIR))
CC = gcc
LIBFLAGS = -L $(LIB_DIR) -lft
MLXPTH = -I /usr/local/include
MLXFLG = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LIBFLAGS) $(MLXPTH) $(MLXFLG)

%.o: %.c
	$(CC) $(CFLAG) $< -o $@

clean:
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all
