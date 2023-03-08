/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:54:33 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:31:45 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_reflect_key(t_data *d)
{
	if (d->first_key_press == 0 && d->all_frame)
	{
		return (0);
	}
	d->sleep_count++;
	if (d->sleep_count == 2)
	{
		usleep(d->stage_frame);
		d->sleep_count = 0;
		return (0);
	}
	d->frame++;
	d->all_frame++;
	if (d->frame >= 8)
		d->frame = 0;
	if (d->eat_stop_count == 0 && d->game_set == 0)
		ft_move_pac(d);
	ft_eat_pellet(d);
	ft_solong_act(d);
	return (0);
}

int	ft_key_released(int key, t_data *d)
{
	if (d->game_set && d->life_stock == 0 && d->game_set_count / 3 > 25)
	{
		ft_continue(d, 0);
	}
	ft_reflect_key(d);
	return (0);
	d->tmp42 = key;
}

int	ft_error(t_data *d, int error_type)
{
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	d->madness = error_type;
	exit (0);
	return (0);
}
