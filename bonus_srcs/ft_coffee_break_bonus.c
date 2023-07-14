/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:13:17 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/14 16:14:11 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_move_dist2(t_data *d, int *x1, int *x2)
{
	*x1 = 0;
	*x2 = 2500;
	if (d->stage_count == 1 || d->stage_count == 2)
	{
		d->cb.add_y = 7;
		d->cb.pac2.move_dist = 270;
		*x2 = 12000;
		if (d->stage_count == 2)
			*x2 = 7000;
	}
	if (d->stage_count == 3)
	{
		d->cb.pac1.move_dist = 210;
		*x2 = 2500;
		d->cb.pac1.type = ANIME_GHOST_RUN;
		d->cb.pac2.type = ANIME_PAC_BIG;
	}
}

void	get_move_dist(t_data *d)
{
	int		width;
	int		x1;
	int		x2;

	d->cb.pac1.type = ANIME_PAC;
	width = (d->map_width + 2) * 1000;
	d->cb.pac1.move_dist = 250;
	d->cb.pac2.move_dist = 290;
	get_move_dist2(d, &x1, &x2);
	while (width > x1)
	{
		x1 += d->cb.pac1.move_dist;
		x2 += d->cb.pac2.move_dist;
	}
	d->cb.pac1.dx = x1;
	d->cb.pac2.dx = x2;
}

void	set_logo_size(t_data *d)
{
	int		height;
	int		width;

	d->cb.start_y = ((double)d->cb.pac1.dy / 1000 * 8 + 10) * d->size;
	d->cb.end_y = ((double)d->cb.pac1.dy / 1000 * 8 + 10 + 32) * d->size;
	height = d->cb.end_y - d->cb.start_y;
	width = height * d->xpm_width2 / d->xpm_height2;
	d->cb.logo_w = width;
	d->cb.logo_h = height;
	d->cb.start_x = d->width / 2 - d->cb.logo_w / 2;
	d->cb.end_x = d->cb.start_x + d->cb.logo_w;
	d->cb.pile = d->cb.start_x + (d->cb.logo_w * 62 / 200);
	d->cb.pac3.sprite_count = 0;
	d->cb.pac3.type = ANIME_PILE;
	d->cb.start_y2 = ((double)d->cb.pac1.dy / 1000 * 8 - 13) * d->size;
	d->cb.end_y2 = ((double)d->cb.pac1.dy / 1000 * 8 + 57) * d->size;
	height = d->cb.end_y2 - d->cb.start_y2;
	width = height * d->xpm_width_c[0] / d->xpm_height_c[0];
	d->cb.logo_w2 = width;
	d->cb.logo_h2 = height;
	d->cb.start_x2 = d->width / 2 - d->cb.logo_w2 / 2;
	d->cb.end_x2 = d->cb.start_x2 + d->cb.logo_w2;
}

void	ft_coffee_break2(t_data *d)
{
	if (d->stage_count == 0)
		put_cb_pac_type1(d);
	else if (d->stage_count == 1)
		put_cb_pac_type2(d);
	else if (d->stage_count == 2)
		put_cb_pac_type3(d);
	else
		put_cb_pac_type4(d);
}

void	ft_coffee_break(t_data *d)
{
	if (d->stage_count > 3)
	{
		d->cb.coffee = 0;
		return ;
	}
	if (d->cb.frame == 0)
	{
		get_move_dist(d);
		set_logo_size(d);
		if (d->stage_count == 2)
			d->cb.pac2.type = ANIME_GHOST2;
	}
	put_fruits_logo(d, &d->fruits);
	d->cb.frame++;
	d->cb.add_y = 0;
	if (d->stage_count == 1 || d->stage_count == 2)
	{
		d->cb.add_y = 7;
		d->cb.pac2.move_dist = 270;
	}
	ft_coffee_break2(d);
}
