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

HDRS_PATH		+= includes/
SRCS_PATH		+= srcs/
OBJS_PATH		+= objs/

#======= FLAGS =======#
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3

MLX		= libmlx.dylib
MLXFLAG	= libmlx.dylib -framework OpenGL -framework AppKit

MINILIB	= minilibx_mms_20200219

SETS	= .sets
INCLUDE_PATH	= mac

SRCS	= $(shell find $(SRCS_PATH) -type f -name "*.c" | sed 's!^.*/!!')
vpath %.c $(SRCS_PATH)

OBJS	+= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

HDRS	= $(HDRS_PATH)/mac/so_long.h

#======= RULES =======#
.PHONY: all
all: $(NAME)

$(NAME): $(SETS) $(OBJS)
	@echo $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJS) -o $(NAME)

$(OBJS_PATH)%.o:	%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJS):			$(HDRS) | $(OBJS_PATH)

$(OBJS_PATH):
					mkdir -p $@

$(SETS):
	cd	"$(PWD)/$(MINILIB)" && make
	-cd	"$(PWD)/$(MINILIB)" && cp mlx.h ../
	-cd	"$(PWD)/$(MINILIB)" && cp $(MLX) ../$(MLX)
	touch $(SETS)

.PHONY: clean
clean:
	rm -rf $(OBJS_PATH)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
