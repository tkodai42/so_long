/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:27:52 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:31:13 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

void	move_jump_pac(t_data *d, t_pac *pac)
{
	if (pac->x <= 0)
	{
		pac->x = d->map_width - 2;
		pac->dx = (d->map_width - 2) * 1000;
	}
	if (pac->x >= d->map_width - 1)
	{
		pac->x = 1;
		pac->dx = 1 * 1000;
	}
	if (pac->y <= 0)
	{
		pac->y = d->map_height - 2;
		pac->dy = (d->map_height - 2) * 1000;
	}
	if (pac->y >= d->map_height - 1)
	{
		pac->y = 1;
		pac->dy = 1 * 1000;
	}
}

void	fixed_blue2(t_data *d, t_pac *pac)
{
	if (pac->blue_time)
	{
		pac->blue_time--;
		if (pac->blue_time == 0 && pac->status == RUN)
			pac->status = CHASE;
	}
	d->tmp42 = 0;
}

void	fixed_blue(t_data *d)
{
	if (d->eat_stop_count == 0)
	{
		fixed_blue2(d, &d->pac_1);
		fixed_blue2(d, &d->pac_2);
		fixed_blue2(d, &d->pac_3);
		fixed_blue2(d, &d->pac_4);
	}
}

void	eat_stop_count(t_data *d)
{
	if (d->eat_stop_count)
		d->eat_stop_count--;
	if (d->eat_time && d->eat_stop_count == 0)
		d->eat_time--;
	if (d->eat_time == 0)
		d->eat_streak = 0;
	if (d->pac_1.vanish_count)
		d->pac_1.vanish_count--;
	if (d->pac_2.vanish_count)
		d->pac_2.vanish_count--;
	if (d->pac_3.vanish_count)
		d->pac_3.vanish_count--;
	if (d->pac_4.vanish_count)
		d->pac_4.vanish_count--;
}
