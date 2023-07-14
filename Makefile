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
NAME3	= so_long_xmas

HDRS_PATH		+= includes/
SRCS_PATH		+= srcs/
OBJS_PATH		+= objs/

B_SRCS_PATH		+= bonus_srcs/
B_OBJS_PATH		+= bonus_objs/

XMAS_SRCS_PATH		+= xmas_srcs/
XMAS_OBJS_PATH		+= xmas_objs/

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

XMAS_SRCS	= $(shell find $(XMAS_SRCS_PATH) -type f -name "*.c" | sed 's!^.*/!!')
vpath %.c $(XMAS_SRCS_PATH)
XMAS_OBJS	+= $(addprefix $(XMAS_OBJS_PATH), $(XMAS_SRCS:.c=.o))

HDRS		= $(HDRS_PATH)/mac/so_long.h
B_HDERS		= $(HDRS_PATH)/mac/so_long_bonus.h
XMAS_HDERS	= $(HDRS_PATH)/mac/so_long_xmas.h

#======= RULES =======#
.PHONY: all
all: $(NAME)

$(NAME): $(SETS) $(OBJS)
	$(CC) $(MINILIB)/$(MLX) $(CFLAGS) $(MLXFLAG) $(OBJS) -o $(NAME)

bonus: $(NAME2)

xmas:	$(NAME3)

$(NAME2): $(SETS) $(B_OBJS)
	@rm -f ./\.HIGH_SCORE.txt
	$(CC) $(MINILIB)/$(MLX) $(CFLAGS) $(MLXFLAG) $(B_OBJS) -o $(NAME2)

$(NAME3): $(SETS) $(XMAS_OBJS)
	@rm -f ./\.HIGH_SCORE.txt
	$(CC) $(MINILIB)/$(MLX) $(CFLAGS) $(MLXFLAG) $(XMAS_OBJS) -o $(NAME3)

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

$(XMAS_OBJS_PATH)%.o:	%.c
					$(CC) -I $(HDRS_PATH)mac -I $(MINILIB) $(CFLAGS) -c $< -o $@

$(XMAS_OBJS):			$(HDRS) | $(XMAS_OBJS_PATH)

$(XMAS_OBJS_PATH):
					mkdir -p $@

$(SETS):
	make -C $(MINILIB)
	cp $(MINILIB)/$(MLX) .

.PHONY: clean
clean:
	rm -rf $(OBJS_PATH)
	rm -rf $(B_OBJS_PATH)
	rm -rf $(XMAS_OBJS_PATH)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f $(NAME3)
	@rm -f ./\.HIGH_SCORE.txt

.PHONY: re
re: fclean all
