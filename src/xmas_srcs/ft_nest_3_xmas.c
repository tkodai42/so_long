/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:28:16 by tkodai            #+#    #+#             */
/*   Updated: 2021/12/23 16:54:14 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

void	nest_into_2(t_data *d, t_pac *pac)
{
	if (pac->color == CYAN && pac->dx >= pac->nest_dx)
	{
		pac->move_dx = -1;
		pac->dx -= 500;
		if (pac->dx <= pac->nest_dx)
		{
			pac->dx = pac->nest_dx - 125;
		}
	}
	else if (pac->color == ORANGE && pac->dx <= pac->nest_dx)
	{
		pac->move_dx = 1;
		pac->dx += 500;
		if (pac->dx >= pac->nest_dx)
		{
			pac->dx = pac->nest_dx + 125;
		}
	}
	else if (d->eat_stop_count == 0)
		pac->nest_status = OUTOF;
}

void	nest_into(t_data *d, t_pac *pac)
{
	if (pac->dx != d->nest.door_c_x * 1000 && pac->dy < \
		(d->nest.door_c_y + 3) * 1000)
	{
		if (pac->dx < d->nest.door_c_x * 1000)
		{
			pac->move_dx = 1;
			pac->dx += 500;
		}
		else if (pac->dx > d->nest.door_c_x * 1000)
		{
			pac->dx -= 500;
			pac->move_dx = -1;
		}
		else
		{
			pac->dx = d->nest.door_c_x * 1000;
			d->bomb_flag = 1;
		}
	}
	else if (pac->dy < (d->nest.door_c_y + 3) * 1000)
	{
		pac->dy += 500;
		pac->move_dy = 1;
		d->bomb_flag = 1;
	}
	else
	{
		d->bomb_flag = 1;
		nest_into_2(d, pac);
	}
}
