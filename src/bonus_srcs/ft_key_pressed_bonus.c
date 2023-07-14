/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:49:25 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/16 17:41:23 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	compatible_key_wasd(int key)
{
	if (key == KEY_W)
		key = KEY_UP;
	if (key == KEY_A)
		key = KEY_LEFT;
	if (key == KEY_D)
		key = KEY_RIGHT;
	if (key == KEY_S)
		key = KEY_DOWN;
	return (key);
}

static void	ft_key_pressed_move(int key, t_data *d)
{
	key = compatible_key_wasd(key);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT)
	{
		if (key == KEY_UP)
			d->key.up = 1;
		if (key == KEY_DOWN)
			d->key.down = 1;
		if (key == KEY_RIGHT)
			d->key.right = 1;
		if (key == KEY_LEFT)
			d->key.left = 1;
		if (d->order_2 == 0)
			d->order_2 = d->order_1;
		d->order_1 = key;
	}
}

int	ft_key_pressed(int key, t_data *d)
{
	d->first_key_press = 1;
	d->key.up = 0;
	d->key.down = 0;
	d->key.right = 0;
	d->key.left = 0;
	if (d->cb.coffee == 1)
	{
		init_coffee(d);
		d->cb.coffee = 0;
	}
	if (VALID_CHEAT == 1 || key == KEY_7)
		ft_key_pressed_cheat(key, d);
	ft_key_pressed_move(key, d);
	if (key == KEY_ESC)
		exit (0);
	if (d->game_set && d->life_stock == 0 && d->game_set_count / 3 > 25)
		ft_continue(d, 0);
	ft_reflect_key(d);
	return (0);
}
