# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkodai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:45:54 by tkodai            #+#    #+#              #
#    Updated: 2022/05/28 13:58:44 by tkodai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long
NAME2	= so_long_bonus
CC		= clang
#CFLAGS	= -Wall -Werror -Wextra -O3 -I.
CFLAGS	= -Wall -Werror -Wextra -O3
MLX		= libmlx.dylib
MLXFLAG	= libmlx.dylib -framework OpenGL -framework AppKit
#MLXFLAG	= libmlx.dylib -framework OpenGL -framework AppKit -g -fsanitize=address
MINILIB	= minilibx_mms_20200219
OS		= $(shell uname)
SETS	= .sets
INCLUDE_PATH	= mac

ifeq ($(OS), Linux)
	MLX =
	MLXFLAG = -Lmlx_linux -lmlx -lXext -lX11 -lm
	MINILIB = mlx_linux
	INCLUDE_PATH = linux
endif

#SRCS	=	$(shell find ./srcs -type f -name "*.c")
SRCS	= 

SRC_M		= srcs/main.c srcs/gnl1.c srcs/put_error.c srcs/libft.c srcs/ft_key.c srcs/ft_read_file.c srcs/ft_check_map.c srcs/xpm_pixel_put.c srcs/some_put.c

SRC_B		=  bonus_srcs/main_bonus.c bonus_srcs/gnl1_bonus.c bonus_srcs/ghost_pac_bonus.c bonus_srcs/ghost_pac_type2_bonus.c bonus_srcs/generate_map_bonus.c bonus_srcs/put_pac_bonus.c bonus_srcs/read_file_bonus.c bonus_srcs/ft_nest_bonus.c bonus_srcs/ft_read_xmp_bonus.c bonus_srcs/put_logo_bonus.c bonus_srcs/put_score_bonus.c bonus_srcs/control_high_score_bonus.c bonus_srcs/put_kill_ghost_score_bonus.c bonus_srcs/ft_continue_bonus.c bonus_srcs/pacman_dying_bonus.c bonus_srcs/ft_set_pellet_bonus.c bonus_srcs/pac_patrol_bonus.c bonus_srcs/set_move_dir_ver2_bonus.c bonus_srcs/generate_out_frame_bonus.c bonus_srcs/ft_fruits_bonus.c bonus_srcs/libft_bonus.c bonus_srcs/ft_coffee_break_bonus.c bonus_srcs/read_file2_bonus.c bonus_srcs/put_life_bonus.c bonus_srcs/put_score_num_bonus.c bonus_srcs/put_score_logo_bonus.c bonus_srcs/put_eye_bonus.c bonus_srcs/put_body_bonus.c bonus_srcs/ft_eat_pellet_bonus.c bonus_srcs/ft_pacman_move_bonus.c bonus_srcs/put_dotmap_bonus.c bonus_srcs/put_cookie_bonus.c bonus_srcs/ft_pixelputs_bonus.c bonus_srcs/ft_action_bonus.c bonus_srcs/ft_action_2_bonus.c bonus_srcs/ft_initpac_bonus.c bonus_srcs/ft_key_cheat_bonus.c bonus_srcs/ft_key_pressed_bonus.c bonus_srcs/ft_key_reflect_bonus.c bonus_srcs/so_long_inits_bonus.c bonus_srcs/ft_cb_set_anime_tex_bonus.c bonus_srcs/ft_fruits_2_bonus.c bonus_srcs/ft_fruits_3_bonus.c bonus_srcs/ft_nest_2_bonus.c bonus_srcs/ghost_pac_type2_gettarget_bonus.c bonus_srcs/ghost_pac_type2_move_xy_bonus.c bonus_srcs/generate_map_nest_bonus.c bonus_srcs/generate_map_nest_2_bonus.c bonus_srcs/generate_out_frame_2_bonus.c bonus_srcs/generate_out_frame_3_bonus.c bonus_srcs/generate_out_frame_4_bonus.c bonus_srcs/generate_map_shape_1_bonus.c bonus_srcs/generate_map_shape_2_bonus.c bonus_srcs/generate_map_shape_3_bonus.c bonus_srcs/ft_coffee_break_2_bonus.c bonus_srcs/ft_coffee_break_3_bonus.c bonus_srcs/ft_coffee_break_4_bonus.c bonus_srcs/ft_coffee_break_5_bonus.c bonus_srcs/ft_coffee_break_6_bonus.c bonus_srcs/ft_nest_3_bonus.c bonus_srcs/ft_coffee_break_7_bonus.c bonus_srcs/get_tex_color_bonus.c bonus_srcs/ft_coffee_break_8_bonus.c bonus_srcs/generate_map_repaint_bonus.c

OBJS 	= $(SRCS:%.c=%.o)
OBJ_M 	= $(SRC_M:%.c=%.o)
OBJ_B	= $(SRC_B:%.c=%.o)

OBJ_FILES = $(OBJS)

all: $(NAME)

$(MLX) :
	cd 	"$(PWD)/$(MINILIB)" && make
	cd 	"$(PWD)/$(MINILIB)" && cp mlx.h ../
	cd 	"$(PWD)/$(MINILIB)" && cp $(MLX) ../$(MLX)

$(SETS)	:
	cd	"$(PWD)/$(MINILIB)" && make
	-cd	"$(PWD)/$(MINILIB)" && cp mlx.h ../
	-cd	"$(PWD)/$(MINILIB)" && cp $(MLX) ../$(MLX)
	-cd	"$(PWD)/includes" && cp ./$(INCLUDE_PATH)/so_long.h ../so_long.h
	-cd	"$(PWD)/includes" && cp ./$(INCLUDE_PATH)/so_long_bonus.h ../so_long_bonus.h
	touch $(SETS)

$(NAME2) : $(SETS) $(OBJ_B)
	@rm -f ./\.HIGH_SCORE.txt
	$(CC) $(OBJ_B) $(MLXFLAG) -o $(NAME2)

$(NAME) : $(SETS) $(OBJ_FILES) $(OBJ_M)
	$(CC) $(OBJ_FILES) $(OBJ_M) $(MLXFLAG) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJ_M) $(OBJ_B)

fclean: clean kill_mlx
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f $(SETS)
	cd 	"$(PWD)/$(MINILIB)" && rm -f $(MLX)
	rm -f libmlx.dylib
	rm -f so_long.h
	rm -f so_long_bonus.h
	@rm -f ./\.HIGH_SCORE.txt

re: fclean all

bonus: $(NAME2)

bonusrun: fclean all_b
	./cub3D map_bonus.cub

norm:
	norminette srcs/ bonus_srcs/ includes/

kill_mlx:
	rm -f $(MLX)
	rm -f mlx.h
	cd 	"$(PWD)/$(MINILIB)" && rm -f $(MLX)

.PHONY: all all_b bonus clean fclean re run kill_mlx
