# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 14:06:22 by bboulhan          #+#    #+#              #
#    Updated: 2022/06/30 02:58:13 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CFLAGS = -Wall -Werror -Wextra 


INCLUDE = cub3d.h

CC = cc

FILES = main.c draw.c

OBJS = ${FILES:.c=.o}

all:$(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "SUUUUUUUUIIIIIII"

%.o : %.c $(INCLUDE)
	gcc  $(CFLAGS) -o $@ -c $<

clean:
	@rm -f ${OBJS}
	@echo "SUUUUUUUUIIIIIII"

fclean: clean
	@rm -f ${NAME}
	@rm -f fdf_bonus
	@echo "SUUUUUUUUIIIIIII"

re: fclean all