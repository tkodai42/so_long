/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:27:29 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:35:47 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_cb_pac3_2(t_data *d, t_pac *pac)
{
	t_tex	tex;
	int		tmp_x;
	int		tmp_y;

	pac->type = ANIME_PAC_BIG;
	tex.x = 0;
	tex.y = 0;
	set_anime_tex(d, pac, &tex);
	while (tex.y < 32)
	{
		tex.x = 0;
		while (tex.x < 32)
		{
			set_anime_color(d, &tex);
			tmp_x = tex.x - 4 + (double)pac->dx / 1000 * 8;
			tmp_y = tex.y - 10 + (double)pac->dy / 1000 * 8;
			if (is_inside_window(d, tmp_x, tmp_y) == 1)
				my_mlx_pixel_put(d, tmp_x, tmp_y, tex.color);
			tex.x++;
		}
		tex.y++;
	}
	pac->type = ANIME_PAC;
}

void	put_cb_pac5(t_data *d, t_pac *pac)
{
	t_tex	tex;
	int		tmp_x;
	int		tmp_y;

	tex.x = 0;
	tex.y = 0;
	set_anime_tex(d, pac, &tex);
	while (tex.y < 32)
	{
		tex.x = 0;
		while (tex.x < 32)
		{
			set_anime_color(d, &tex);
			tmp_x = 32 - (tex.x - 4) + (double)pac->dx / 1000 * 8;
			tmp_y = tex.y - 14 + (double)pac->dy / 1000 * 8;
			if (is_inside_window(d, tmp_x, tmp_y) == 1)
				my_mlx_pixel_put(d, tmp_x, tmp_y, tex.color);
			tex.x++;
		}
		tex.y++;
	}
	d->cb.valid_x = ((double)pac->dx / 1000 * 8 + 24) * d->size;
	if (pac->type == ANIME_PAC_BIG)
		put_cb_logo(d, 1);
}

void	put_cb_pac_type4_2(t_data *d)
{
	int		width;
	int		x1;
	int		x2;

	d->cb.pac1.move_dx = 1;
	d->cb.pac2.move_dx = 1;
	d->cb.pac2.type = ANIME_PAC;
	d->cb.pac1.type = ANIME_GHOST1;
	d->cb.pac1.move_dist = 330;
	d->cb.pac2.move_dist = 300;
	x1 = 18000;
	x2 = 0;
	width = (d->map_width) * 1000;
	while (width > x2)
	{
		x1 += d->cb.pac1.move_dist;
		x2 += d->cb.pac2.move_dist;
	}
	d->cb.pac1.dx = x1 * -1 + width;
	d->cb.pac2.dx = x2 * -1 + width;
	d->cb.pac4_2.dx = d->cb.pac1.dx - 18000;
	d->cb.pac4_3.dx = d->cb.pac1.dx - 18000 * 2;
	d->cb.pac4_4.dx = d->cb.pac1.dx - 18000 * 3;
}

void	put_cb_pac_type4_put(t_data *d)
{
	if (d->cb.pac2.type == ANIME_PAC_BIG)
	{
		put_cb_pac2(d, &d->cb.pac1);
		put_cb_pac5(d, &d->cb.pac2);
	}
	else
	{
		d->cb.pac4_2.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
		d->cb.pac4_3.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
		d->cb.pac4_4.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
		put_cb_pac3_2(d, &d->cb.pac2);
		put_cb_pac6(d, &d->cb.pac1);
		put_cb_pac6(d, &d->cb.pac4_2);
		put_cb_pac6(d, &d->cb.pac4_3);
		put_cb_pac6(d, &d->cb.pac4_4);
	}
}

void	put_cb_pac_type4(t_data *d)
{
	d->cb.add_y = 7;
	d->cb.pac2.dx += d->cb.pac2.move_dist * d->cb.pac2.move_dx;
	d->cb.pac1.dx += d->cb.pac1.move_dist * d->cb.pac1.move_dx;
	put_cb_pac_type4_put(d);
	if (d->cb.pac2.dx < -12000 && d->cb.pac2.type == ANIME_PAC_BIG)
	{
		put_cb_pac_type4_2(d);
	}
	if (d->cb.pac4_4.dx > d->map_width * 1000 + 8000 && \
		d->cb.pac2.type == ANIME_PAC)
	{
		real_clear(d);
		put_fruits_logo(d, &d->fruits);
		d->cb.coffee = 0;
		init_coffee(d);
	}
}
