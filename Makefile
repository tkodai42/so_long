# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkodai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:45:54 by tkodai            #+#    #+#              #
#    Updated: 2021/08/20 18:34:38 by tkodai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#======= PROGS =======#
NAME	= so_long
NAME2	= so_long_bonus

HDRS_PATH		+= includes/
SRCS_PATH		+= srcs/
OBJS_PATH		+= objs/

B_SRCS_PATH		+= bonus_srcs/
B_OBJS_PATH		+= bonus_objs/

#======= FLAGS =======#
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3

MLX		= libmlx.dylib
MLXFLAG	= -framework OpenGL -framework AppKit

MINILIB	= minilibx_mms_20200219

SETS	= $(MINILIB)/$(MLX)
INCLUDE_PATH	= mac

SRCS	= $(shell find $(SRCS_PATH) -type f -name "*.c" | sed 's!^.*/!!')
vpath %.c $(SRCS_PATH)
OBJS	+= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

B_SRCS	= $(shell find $(B_SRCS_PATH) -type f -name "*.c" | sed 's!^.*/!!')
vpath %.c $(B_SRCS_PATH)
B_OBJS	+= $(addprefix $(B_OBJS_PATH), $(B_SRCS:.c=.o))

HDRS	= $(HDRS_PATH)/mac/so_long.h
B_HDERS	= $(HDRS_PATH)/mac/so_long_bonus.h

#======= RULES =======#
.PHONY: all
all: $(NAME)

$(NAME): $(SETS) $(OBJS)
	$(CC) $(MINILIB)/$(MLX) $(CFLAGS) $(MLXFLAG) $(OBJS) -o $(NAME)

bonus: $(NAME2)

$(NAME2): $(SETS) $(B_OBJS)
	@rm -f ./\.HIGH_SCORE.txt
	$(CC) $(MINILIB)/$(MLX) $(CFLAGS) $(MLXFLAG) $(B_OBJS) -o $(NAME2)

$(OBJS_PATH)%.o:	%.c
					$(CC) -I $(HDRS_PATH)mac -I $(MINILIB) $(CFLAGS) -c $< -o $@

$(OBJS):			$(HDRS) | $(OBJS_PATH)

$(OBJS_PATH):
					mkdir -p $@

$(B_OBJS_PATH)%.o:	%.c
					$(CC) -I $(HDRS_PATH)mac -I $(MINILIB) $(CFLAGS) -c $< -o $@

$(B_OBJS):			$(HDRS) | $(B_OBJS_PATH)

$(B_OBJS_PATH):
					mkdir -p $@

$(SETS):
	make -C $(MINILIB)

.PHONY: clean
clean:
	rm -rf $(OBJS_PATH)
	rm -rf $(B_OBJS_PATH)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	@rm -f ./\.HIGH_SCORE.txt

.PHONY: re
re: fclean all