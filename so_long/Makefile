# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beeren <beeren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 14:02:41 by beeren            #+#    #+#              #
#    Updated: 2023/09/11 21:27:46 by beeren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
BNAME			=	so_long_bonus
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC := ./mainfile/main.c  ./mainfile/map_control.c ./mainfile/putimage.c ./mainfile/movement_control.c ./mainfile/input.c \
		./mainfile/utils.c ./mainfile/start_game.c ./mainfile/map_validation.c 
BONUS_SRC := ./mainbonus/main_bonus.c  ./mainbonus/map_control_bonus.c ./mainbonus/putimage_bonus.c ./mainbonus/movement_control_bonus.c \
		./mainbonus/input_bonus.c ./mainbonus/utils_bonus.c ./mainbonus/start_game_bonus.c ./mainbonus/map_validation_bonus.c 

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX_PATH	=	minilibx

all:				$(NAME)

$(NAME): mlx
					$(CC) $(CFLAGS) -o $(NAME) $(SRC) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx


mlx:
					make -C $(MINILIBX_PATH) all

bonus : mlx $(BNAME)

$(BNAME):
					$(CC) $(CFLAGS) -o $(BNAME) $(BONUS_SRC) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

clean:
					$(RM) $(NAME)
					$(RM) $(BNAME)

fclean: clean
					make clean -C $(MINILIBX_PATH)
					
re:					fclean mlx all

.PHONY:				all clean fclean re bonus