/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_continue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:57:59 by tkodai            #+#    #+#             */
/*   Updated: 2021/12/24 19:54:38 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_continue3(t_data *d, int flag)
{
	if (flag == 0)
	{
		d->score = 0;
		ft_set_pellet(d);
		d->pellet_num = d->pellet_num_og;
		d->life_score = 0;
		d->stage_frame = DEFAULT_SPEED;
		d->stage_count = 0;
		d->life_stock = 0; // change 2->0
		init_fruits(d, &d->fruits);
	}
	d->game_set_count = 0;
	d->fruits.put_mode = FRUITS_HIDE;
	d->fruits.put_count = 0;
	d->pac_mine.x = d->pac_mine.init_x;
	d->pac_mine.y = d->pac_mine.init_y;
	d->pac_mine.dx = d->pac_mine.init_dx;
	d->pac_mine.dy = d->pac_mine.init_dy;
	d->pac_mine.sprite_count = 0;
}

void	ft_continue2(t_data *d, int flag)
{
	if (flag == 3)
		d->score = 0;
	read_high_score(d);
	d->game_set = 0;
	d->madness = 0;
	d->eat_stop_count = 0;
	d->eat_time = 0;
	d->eat_streak = 0;
	if (flag == 2)
	{
		ft_set_pellet(d);
		d->pellet_num = d->pellet_num_og;
		d->stage_frame += -1000;
		d->stage_count++;
		level_up_fruits(d, &d->fruits);
		if (d->stage_frame <= 0)
			d->stage_frame = 0;
	}
	else
		d->life_stock--;
	ft_continue3(d, flag);
}

void	ft_continue(t_data *d, int flag)
{
	d->first_key_press = 0;
	d->show_root = 0;
	d->frame = 0;
	d->all_frame = 0;
	d->key.up = 0;
	d->key.down = 0;
	d->key.right = 0;
	d->key.left = 0;
	d->order_1 = 0;
	d->order_2 = 0;
	d->executed = KEY_LEFT;
	ft_init_pac(d, &d->pac_1, 1, 1);
	ft_init_pac(d, &d->pac_2, 1, 1);
	ft_init_pac(d, &d->pac_3, 1, 1);
	ft_init_pac(d, &d->pac_4, 1, 1);
	d->nest.p1 = NULL;
	d->nest.p2 = NULL;
	d->nest.p3 = NULL;
	d->nest.p4 = NULL;
	d->nest.count = 0;
	d->nest.scramble = 0;
	ft_continue2(d, flag);
}
