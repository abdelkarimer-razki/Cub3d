# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:30:47 by bboulhan          #+#    #+#              #
#    Updated: 2022/09/15 16:30:20 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra

CC = cc

HEADER =  cub3D.h \

FILES = cub3D.c ./utils/utils.c ./utils/utils_2.c ./parsing/parsing.c ./parsing/checking_utils.c \
		./parsing/check_map.c ./draw/draw2.c ./draw/main2.c ./parsing/parsing_utils.c ./utils/ft_itoa.c ./utils/ft_split.c \

OBJS = $(FILES:.c=.o)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	clear

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : re fclean clean all