/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:13:17 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/13 13:53:47 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_cb_pac_type3(t_data *d)
{
	d->cb.pac1.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
	d->cb.pac2.dx += d->cb.pac2.move_dist * d->cb.pac2.move_dx;
	put_cb_logo(d, 2);
	d->cb.pac3.sprite_count = 80;
	put_cb_pac2(d, &d->cb.pac3);
	put_cb_pac2(d, &d->cb.pac1);
	if (d->cb.pac2.type == ANIME_GHOST3)
		put_cb_pac4(d, &d->cb.pac2);
	else
		put_cb_pac2(d, &d->cb.pac2);
	if (d->cb.pac2.dx < -6000 && d->cb.pac2.type == ANIME_GHOST2)
	{
		d->cb.pac2.move_dx = 1;
		d->cb.pac2.type = ANIME_GHOST3;
		d->cb.pac2.move_dist = 450;
	}
	if (d->cb.pac2.dx > (d->map_width + 2) * 1000 + 6000 && \
			d->cb.pac2.type == ANIME_GHOST3)
	{
		real_clear(d);
		put_fruits_logo(d, &d->fruits);
		d->cb.coffee = 0;
		init_coffee(d);
	}
}

void	put_cb_pac_type2_2(t_data *d)
{
	int		pos;

	d->cb.pac3.sprite_count++;
	pos = d->cb.pac3.sprite_count / 4 + 1;
	if (d->cb.pac3.sprite_count < 36)
		d->cb.pac2.dx = d->cb.pac3.dx - pos * 100;
	else if (d->cb.pac3.sprite_count < 61)
		d->cb.pac2.dx = d->cb.pac3.dx - 9 * 100;
	else
		d->cb.pac2.dx = d->cb.pac3.dx - 11 * 100;
}

void	put_cb_pac_type2(t_data *d)
{
	d->cb.pac1.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
	d->cb.pac2.dx += d->cb.pac2.move_dist * d->cb.pac2.move_dx;
	d->cb.pac3.dx = d->cb.pile / d->size * 1000 / 8 - 16 * 100;
	d->cb.pac3.dy = d->cb.pac2.dy;
	if (d->cb.pac2.dx < d->cb.pac3.dx)
	{
		put_cb_pac_type2_2(d);
	}
	put_cb_logo(d, 2);
	put_cb_pac2(d, &d->cb.pac3);
	put_cb_pac2(d, &d->cb.pac1);
	put_cb_pac2(d, &d->cb.pac2);
	if (d->cb.pac3.sprite_count > 120)
	{
		real_clear(d);
		put_fruits_logo(d, &d->fruits);
		d->cb.coffee = 0;
		init_coffee(d);
	}
}

void	put_cb_pac_type1_2(t_data *d)
{
	int		width;
	int		x1;
	int		x2;
	int		tmp;

	d->cb.pac1.move_dx = 1;
	d->cb.pac2.move_dx = 1;
	d->cb.pac1.type = ANIME_PAC_BIG;
	d->cb.pac2.type = ANIME_GHOST_RUN;
	tmp = d->cb.pac1.move_dist;
	d->cb.pac1.move_dist = d->cb.pac2.move_dist;
	d->cb.pac2.move_dist = tmp;
	x1 = 4300;
	x2 = 0;
	width = (d->map_width) * 1000;
	while (width > x2)
	{
		x1 += d->cb.pac1.move_dist;
		x2 += d->cb.pac2.move_dist;
	}
	d->cb.pac1.dx = x1 * -1 + width;
	d->cb.pac2.dx = x2 * -1 + width;
}

void	put_cb_pac_type1(t_data *d)
{
	d->cb.pac1.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
	d->cb.pac2.dx += d->cb.pac2.move_dist * d->cb.pac2.move_dx;
	if (d->cb.pac1.type == ANIME_PAC_BIG)
		put_cb_pac3(d, &d->cb.pac1);
	else
		put_cb_pac2(d, &d->cb.pac1);
	put_cb_pac2(d, &d->cb.pac2);
	if (d->cb.pac2.dx < -8000 && d->cb.pac1.type == ANIME_PAC)
	{
		put_cb_pac_type1_2(d);
	}
	if (d->cb.pac1.dx > d->cb.pac1.home_pos_dx + 10000)
	{		
		real_clear(d);
		put_fruits_logo(d, &d->fruits);
		d->cb.coffee = 0;
		init_coffee(d);
	}
}
