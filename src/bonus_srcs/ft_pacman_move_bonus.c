/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacman_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:37:26 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:27:48 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

typedef struct s_move_pac
{
	int		mod_dx;
	int		mod_dy;
	int		move_x;
	int		move_y;
	int		executed;
}				t_move_pac;

void	get_move_xy(int order, int *x, int *y)
{
	if (order == KEY_UP)
	{
		*y = -1;
	}
	if (order == KEY_DOWN)
	{
		*y = 1;
	}
	if (order == KEY_RIGHT)
	{
		*x = 1;
	}
	if (order == KEY_LEFT)
	{
		*x = -1;
	}
}

void	try_exec_order2(t_data *d, t_move_pac *mp)
{
	if (mp->mod_dx == 0 && (d->order_2 == KEY_UP || d->order_2 == KEY_DOWN))
	{
		if (mp->mod_dy != 0 || \
				d->map[d->pac_mine.y + mp->move_y][d->pac_mine.x] == '0')
		{
			d->pac_mine.dy += MOVE_SPEED * mp->move_y;
			d->pac_mine.sprite_count++;
			d->move_count_d += MOVE_SPEED;
		}
		d->executed = d->order_2;
	}
	if (mp->mod_dy == 0 && (d->order_2 == KEY_LEFT || d->order_2 == KEY_RIGHT))
	{
		if (mp->mod_dx != 0 || \
				d->map[d->pac_mine.y][d->pac_mine.x + mp->move_x] == '0')
		{
			d->pac_mine.dx += MOVE_SPEED * mp->move_x;
			d->pac_mine.sprite_count++;
			d->move_count_d += MOVE_SPEED;
		}
		d->executed = d->order_2;
	}
}

void	try_exec_order1_2(t_data *d, t_move_pac *mp)
{
	if (mp->mod_dx != 0 || \
			d->map[d->pac_mine.y][d->pac_mine.x + mp->move_x] == '0')
	{
		d->pac_mine.dx += MOVE_SPEED * mp->move_x;
		mp->executed = 1;
		d->pac_mine.sprite_count++;
		d->move_count_d += MOVE_SPEED;
	}
	if (d->pac_mine.dx % 1000 == 0)
		d->pac_mine.x = d->pac_mine.dx / 1000;
}

void	try_exec_order1(t_data *d, t_move_pac *mp)
{
	if (mp->mod_dx == 0 && (d->order_1 == KEY_UP || d->order_1 == KEY_DOWN))
	{
		if (mp->mod_dy != 0 || \
				d->map[d->pac_mine.y + mp->move_y][d->pac_mine.x] == '0')
		{
			d->pac_mine.dy += MOVE_SPEED * mp->move_y;
			mp->executed = 1;
			d->pac_mine.sprite_count++;
			d->move_count_d += MOVE_SPEED;
		}
		if (d->pac_mine.dy % 1000 == 0)
			d->pac_mine.y = d->pac_mine.dy / 1000;
	}
	if (mp->mod_dy == 0 && (d->order_1 == KEY_LEFT || d->order_1 == KEY_RIGHT))
	{
		try_exec_order1_2(d, mp);
	}
}

void	ft_move_pac(t_data *d)
{
	t_move_pac	mp;

	mp.mod_dx = d->pac_mine.dx % 1000;
	mp.mod_dy = d->pac_mine.dy % 1000;
	mp.move_x = 0;
	mp.move_y = 0;
	mp.executed = 0;
	get_move_xy(d->order_1, &mp.move_x, &mp.move_y);
	try_exec_order1(d, &mp);
	if (mp.executed == 1)
	{
		d->executed = d->order_1;
		d->order_2 = 0;
		return ;
	}
	mp.move_x = 0;
	mp.move_y = 0;
	get_move_xy(d->order_2, &mp.move_x, &mp.move_y);
	try_exec_order2(d, &mp);
	if (d->pac_mine.dx % 1000 == 0)
		d->pac_mine.x = d->pac_mine.dx / 1000;
	if (d->pac_mine.dy % 1000 == 0)
		d->pac_mine.y = d->pac_mine.dy / 1000;
}
