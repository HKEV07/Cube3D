# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 02:59:36 by fel-hazz          #+#    #+#              #
#    Updated: 2023/10/07 19:37:36 by fel-hazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3D

MLX42_DIR = "/Users/fel-hazz/.brew/Cellar/glfw/3.3.8/lib"

LIBMLX42_DIR = /Users/fel-hazz/libmlx42.a

INCLUDES = Mandatory/cube3D.h

LIB = $(LIBMLX42_DIR) -ldl -lglfw -L $(MLX42_DIR) libft.a

SRCS = Mandatory/raycasting/main.c Mandatory/parsing/colors.c Mandatory/parsing/textures.c Mandatory/parsing/map1.c Mandatory/parsing/map2.c Mandatory/parsing/map3.c \
		Mandatory/raycasting/raycasting.c Mandatory/raycasting/raycasting1.c Mandatory/raycasting/player_movement.c 

OBJS = ${SRCS:.c=.o}

NAME_BONUS = cube3D_bonus

INCLUDES_BONUS = Bonus/cube3D_bonus.h

SRCS_BONUS = Bonus/raycasting/main_bonus.c Bonus/parsing/colors_bonus.c Bonus/parsing/textures_bonus.c Bonus/parsing/map1_bonus.c Bonus/parsing/map2_bonus.c Bonus/parsing/map3_bonus.c \
		Bonus/raycasting/raycasting_bonus.c Bonus/raycasting/raycasting1_bonus.c Bonus/raycasting/player_movement_bonus.c Bonus/raycasting/sprite1_bonus.c \
		Bonus/raycasting/collision_bonus.c Bonus/raycasting/collision1_bonus.c Bonus/raycasting/doors_bonus.c Bonus/raycasting/doors1_bonus.c \
		Bonus/raycasting/tools_bonus.c Bonus/raycasting/draw_map_bonus.c Bonus/raycasting/draw_map1_bonus.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}


CC = cc

CFLAGS = -Wall -Wextra -Werror 

%.o: %.c ${INCLUDES}
	@${CC} ${CFLAGS} -c $< -o $@

%_bonus.o: %_bonus.c ${INCLUDES_BONUS}
	@${CC} ${CFLAGS} -c $< -o $@
	
all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${LIB} ${OBJS} libft.a -o ${NAME}
	@echo "\033[32m[cube3D is ready!]\033[0m"

clean : 
	@echo "\033[32m[clean]\033[0m"

bonus : ${NAME_BONUS}

${NAME_BONUS} : ${OBJS_BONUS}
	@${CC} ${CFLAGS} ${LIB} ${OBJS_BONUS} libft.a -o ${NAME_BONUS}
	@echo "\033[32m[cube3D_bonus is ready!]\033[0m"
	
fclean :
	@rm  -rf ${NAME} ${NAME_BONUS}
	@rm -rf ${OBJS} ${OBJS_BONUS}
	@echo "\033[32m[fclean]\033[0m"

re : fclean all

.PHONY: clean fclean all re 