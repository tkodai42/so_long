/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_cheat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:44:13 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/16 17:41:25 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_key_pressed_cheat1(int key, t_data *d)
{
	if (key == KEY_3)
	{
		if (d->pac_1.status == CHASE || d->pac_1.status == RUN)
		{
			d->pac_1.status = RUN;
			d->pac_1.blue_time = 150;
		}
		if (d->pac_2.status == CHASE || d->pac_2.status == RUN)
		{
			d->pac_2.status = RUN;
			d->pac_2.blue_time = 150;
		}
		if (d->pac_3.status == CHASE || d->pac_3.status == RUN)
		{
			d->pac_3.status = RUN;
			d->pac_3.blue_time = 150;
		}
		if (d->pac_4.status == CHASE || d->pac_4.status == RUN)
		{
			d->pac_4.status = RUN;
			d->pac_4.blue_time = 150;
		}
	}
}

static void	ft_key_pressed_cheat2(int key, t_data *d)
{
	if (key == KEY_1)
		d->show_root = 1;
	if (key == KEY_2)
		d->show_root = 0;
	if (key == KEY_4)
		ft_continue(d, 2);
	if (key == KEY_5)
	{
		ft_set_pellet(d);
		d->life_stock++;
	}
	if (key == KEY_6)
	{
		ft_init_pac(d, &d->pac_1, 1, 1);
		ft_init_pac(d, &d->pac_2, 1, 1);
		ft_init_pac(d, &d->pac_3, 1, 1);
		ft_init_pac(d, &d->pac_4, 1, 1);
	}
	if (key == KEY_7)
	{
		if (d->move_count_is_valid)
			d->move_count_is_valid = 0;
		else
			d->move_count_is_valid = 1;
	}
}

void	ft_key_pressed_cheat(int key, t_data *d)
{
	ft_key_pressed_cheat1(key, d);
	ft_key_pressed_cheat2(key, d);
	if (key == KEY_8)
	{
		if (d->madness)
			d->madness = 0;
		else
			d->madness = 1;
	}
	if (key == KEY_M)
	{
		d->pellet_num = 0;
	}
	if (key == KEY_PLUS || key == KEY_MINUS)
	{
		if (key == KEY_PLUS)
			d->stage_frame += 1000;
		if (key == KEY_MINUS)
		{
			d->stage_frame -= 1000;
			if (d->stage_frame <= 0)
				d->stage_frame = 0;
		}
		printf(" game speed [%d]\n", d->stage_frame);
	}
}
