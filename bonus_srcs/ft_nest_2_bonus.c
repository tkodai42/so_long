/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:28:16 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/13 14:16:07 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	nest_outof_2(t_data *d, t_pac *pac)
{
	if (pac->dy > d->nest.door_c_y * 1000)
	{
		pac->dy -= 125;
		pac->move_dy = -1;
	}
	else
	{
		pac->status = CHASE;
		if (pac->blue_time)
			pac->status = RUN;
		pac->nest_status = INTO;
		pac->x = d->nest.door_c_x;
		pac->y = d->nest.door_c_y;
		pac->dx = pac->x * 1000;
		pac->dy = pac->y * 1000;
		pac->move_dx = 0;
		pac->move_dy = 0;
	}
}

void	nest_outof(t_data *d, t_pac *pac)
{
	if (pac->dx != d->nest.door_c_x * 1000)
	{
		if (pac->dx < d->nest.door_c_x * 1000)
		{
			pac->move_dx = 1;
			pac->dx += 125;
		}
		else if (pac->dx > d->nest.door_c_x * 1000)
		{
			pac->move_dx = -1;
			pac->dx -= 125;
		}
		else
			pac->dx = d->nest.door_c_x * 1000;
	}
	else
		nest_outof_2(d, pac);
}

void	nest_hold_2(t_data *d, t_pac *pac)
{
	if (pac == &(d->pac_2) && d->all_frame >= 0)
		pac->nest_status = OUTOF;
	if (pac == &(d->pac_3) && d->all_frame >= 210 - d->stage_count * 210)
		pac->nest_status = OUTOF;
	if (pac == &(d->pac_4) && d->all_frame >= 310 - d->stage_count * 210)
		pac->nest_status = OUTOF;
}

void	nest_hold(t_data *d, t_pac *pac)
{
	int		move_pos_y;

	move_pos_y = 0;
	if (d->all_frame <= 1)
		move_pos_y = 0;
	else if (d->all_frame < 6)
		move_pos_y = -125;
	else if ((d->all_frame + 5) % 20 > 9)
		move_pos_y = 125;
	else
		move_pos_y = -125;
	if (pac == &(d->pac_2))
	{
		pac->dy -= move_pos_y;
		pac->move_dy -= move_pos_y;
	}
	else
	{
		pac->dy += move_pos_y;
		pac->move_dy = move_pos_y;
	}
	nest_hold_2(d, pac);
}
