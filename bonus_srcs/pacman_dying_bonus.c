/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman_dying.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:45:51 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:20:58 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//(double)pac->dx / 1000 * 8 , y + (double)pac->dy / 1000 * 8

void	set_tex_dying_pac(t_tex *tex, int pos)
{
	tex->start_x = 6 + pos * 20;
	tex->end_x = 22 + pos * 20;
	tex->start_y = 246;
	tex->end_y = 262;
}

void	pacman_dying2(t_data *d, t_pac *pac, int dying_time)
{
	int		color;
	int		x;
	int		y;
	t_tex	tex;

	color = 0;
	set_tex_dying_pac(&tex, dying_time);
	y = 0;
	while (y <= 16)
	{
		x = 0;
		while (x <= 16)
		{
			color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
			if (color != 0)
				my_mlx_pixel_put(d, x - 3 + (double)pac->dx / 1000 * 8, \
					y - 3 + (double)pac->dy / 1000 * 8, color);
			x++;
		}
		y++;
	}
}

void	pacman_dying3(t_data *d, int dying_time)
{
	ft_clear_window(d);
	if (d->cb.coffee == 1)
		return ;
	if (dying_time > 16)
	{
		ft_continue(d, 2);
		return ;
	}
	d->cb.coffee = 1;
}

void	pacman_dying(t_data *d)
{
	int		dying_time;

	dying_time = d->game_set_count / 3;
	dying_time += -7;
	if (d->pellet_num)
	{
		if (dying_time <= 0)
			dying_time = 0;
		if (dying_time <= 17)
			pacman_dying2(d, &(d->pac_mine), dying_time);
		if (dying_time > 10000)
			d->game_set_count = 10000;
		if (d->life_stock != 0)
		{
			if (dying_time > 21)
				ft_clear_window(d);
			if (dying_time > 23)
				ft_continue(d, 1);
		}
	}
	else
		pacman_dying3(d, dying_time);
}
