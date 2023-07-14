/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:13:17 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/14 16:14:43 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

void	init_coffee2(t_data *d)
{
	d->cb.pac4_2.move_dx = -1;
	d->cb.pac4_3.move_dx = -1;
	d->cb.pac4_4.move_dx = -1;
	d->cb.pac4_2.sprite_count = 0;
	d->cb.pac4_3.sprite_count = 0;
	d->cb.pac4_4.sprite_count = 0;
	d->cb.pac4_2.dy = d->cb.pac1.home_pos_dy;
	d->cb.pac4_3.dy = d->cb.pac1.home_pos_dy;
	d->cb.pac4_4.dy = d->cb.pac1.home_pos_dy;
	d->cb.pac4_2.type = ANIME_GHOST1;
	d->cb.pac4_3.type = ANIME_GHOST1;
	d->cb.pac4_4.type = ANIME_GHOST1;
	d->cb.pac1.color = RED;
	d->cb.pac4_2.color = PINK;
	d->cb.pac4_3.color = CYAN;
	d->cb.pac4_4.color = ORANGE;
	d->cb.pac1.cb_tex = 0;
	d->cb.pac4_2.cb_tex = 1;
	d->cb.pac4_3.cb_tex = 2;
	d->cb.pac4_4.cb_tex = 3;
}

void	init_coffee(t_data *d)
{
	d->cb.frame = 0;
	d->cb.pac1.move_dx = -1;
	d->cb.pac1.move_dy = 0;
	d->cb.pac1.sprite_count = 0;
	d->cb.pac2.move_dx = -1;
	d->cb.pac2.move_dy = 0;
	d->cb.pac2.sprite_count = 0;
	d->cb.pac1.home_pos_dx = (d->map_width + 1) * 1000;
	d->cb.pac1.home_pos_dy = (d->map_height / 2) * 1000;
	d->cb.pac2.home_pos_dx = (d->map_width + 4) * 1000;
	d->cb.pac2.home_pos_dy = (d->map_height / 2) * 1000;
	d->cb.pac1.dx = d->cb.pac1.home_pos_dx;
	d->cb.pac1.dy = d->cb.pac1.home_pos_dy;
	d->cb.pac2.dx = d->cb.pac2.home_pos_dx;
	d->cb.pac2.dy = d->cb.pac2.home_pos_dy;
	d->cb.pac1.move_dist = 250;
	d->cb.pac2.move_dist = 290;
	d->cb.coffee = 0;
	d->cb.pac1.type = ANIME_PAC;
	d->cb.pac2.type = ANIME_GHOST1;
	d->cb.pac3.sprite_count = 0;
	init_coffee2(d);
}
