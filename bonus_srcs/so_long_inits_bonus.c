/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:55:56 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/12 12:32:34 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	fix_max_size_window(t_data *d)
{
	int		size;
	int		max_w;
	int		max_h;

	d->width = 0;
	d->height = 0;
	size = 1;
	mlx_get_screen_size(d->mlx_ptr, &max_w, &max_h);
	while (1)
	{
		if (d->width >= max_w || d->height >= max_h)
		{
			d->size = size - 1;
			d->width = d->map_width * 8 * d->size;
			d->height = (d->map_height + 5) * 8 * d->size;
			return ;
		}
		size++;
		d->width = d->map_width * 8 * size;
		d->height = (d->map_height + 5) * 8 * size;
	}
}

void	ft_solong_init_3(t_data *d)
{
	d->sleep_count = 0;
	d->game_set = 0;
	d->madness = 0;
	d->eat_stop_count = 0;
	d->eat_time = 0;
	d->eat_streak = 0;
	d->life_stock = 2;
	d->game_set_count = 0;
	d->clear_flag = 0;
	d->stage_frame = DEFAULT_SPEED;
	d->stage_count = 0;
}

void	ft_solong_init_2(t_data *d)
{
	ft_init_pac(d, &d->pac_1, 1, 1);
	ft_init_pac(d, &d->pac_2, 1, 1);
	ft_init_pac(d, &d->pac_3, 1, 1);
	ft_init_pac(d, &d->pac_4, 1, 1);
	d->pac_1.color = RED;
	d->pac_2.color = PINK;
	d->pac_3.color = CYAN;
	d->pac_4.color = ORANGE;
	d->nest.p1 = NULL;
	d->nest.p2 = NULL;
	d->nest.p3 = NULL;
	d->nest.p4 = NULL;
	d->nest.count = 0;
	d->nest.scramble = 0;
	d->score = 0;
	d->life_score = 0;
}

void	ft_solong_init_1(t_data *d)
{
	if (d->size_set == 1)
	{
		d->width = d->map_width * 8 * d->size;
		d->height = (d->map_height + 5) * 8 * d->size;
	}
	else
		fix_max_size_window(d);
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
	d->executed = KEY_DOWN;
}
