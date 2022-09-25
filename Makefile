# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:30:47 by bboulhan          #+#    #+#              #
#    Updated: 2022/09/24 21:27:19 by bboulhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra -Ofast -Os 

CC = cc

HEADER =  cub3D.h \

FILES = cub3D.c ./utils/utils.c ./utils/utils_2.c ./parsing/parsing.c ./parsing/checking_utils.c \
		./parsing/check_map.c ./draw/draw2.c ./draw/main2.c ./parsing/parsing_utils.c \
		./utils/ft_split.c ./parsing/files_checker.c  ./draw/draw_utils.c ./draw/render_pixels.c\
		./draw/wall_detection.c ./draw/control_player.c ./draw/control_player_2.c ./draw/putting_pixels.c\

OBJS = $(FILES:.c=.o)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -static-libsan -fsanitize=address
	clear

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : re fclean clean all