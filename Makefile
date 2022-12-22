# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:30:47 by bboulhan          #+#    #+#              #
#    Updated: 2022/12/22 14:54:56 by aer-razk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra -Ofast -Os 

CC = cc

GREEN=\033[0;32m

NC=\033[0m

HEADER =  cub3D.h \

FILES = cub3D.c ./utils/utils.c ./utils/utils_2.c ./parsing/parsing.c ./parsing/checking_utils.c \
		./parsing/check_map.c ./draw/draw2.c ./draw/main2.c ./parsing/parsing_utils.c \
		./utils/ft_split.c ./parsing/files_checker.c  ./draw/draw_utils.c ./draw/render_pixels.c\
		./draw/wall_detection.c ./draw/control_player.c ./draw/control_player_2.c ./draw/putting_pixels.c\
		./utils/ft_strtrim.c \

OBJS = $(FILES:.c=.o)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear

all : $(NAME)
	@echo "$(GREEN)✔$(NC) Compiled."

$(NAME) : $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -static-libsan -fsanitize=address
	@clear

clean : 
	@rm -f $(OBJS)
	@clear

fclean : clean
	@rm -f $(NAME)
	@clear
	@echo "$(GREEN)✔$(NC) Cleaned."

re : fclean all

.PHONY : re fclean clean all