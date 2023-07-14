/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_pac_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:16:29 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:38:58 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	pac_on_middle_gird(t_data *d, t_pac *pac)
{
	if (pac->dx % 1000 != 0)
		return (1);
	if (pac->dy % 1000 != 0)
		return (1);
	return (0);
	d->tmp42 = 0;
}

int	pac_on_dead_end(t_data *d, t_pac *pac)
{
	int		branch;

	branch = 0;
	if (d->map[pac->y - 1][pac->x] == '0')
		branch++;
	if (d->map[pac->y + 1][pac->x] == '0')
		branch++;
	if (d->map[pac->y][pac->x - 1] == '0')
		branch++;
	if (d->map[pac->y][pac->x + 1] == '0')
		branch++;
	if (branch == 1)
		return (1);
	return (0);
}

int	pac_on_branch(t_data *d, t_pac *pac)
{
	int		branch;

	branch = 0;
	if (pac_on_middle_gird(d, pac) == 1)
	{
		return (0);
	}
	if (d->map[pac->y - 1][pac->x] == '0' || d->map[pac->y + 1][pac->x] == '0')
		branch++;
	if (d->map[pac->y][pac->x - 1] == '0' || d->map[pac->y][pac->x + 1] == '0')
		branch++;
	if (branch >= 2)
		return (1);
	return (pac_on_dead_end(d, pac));
	return (0);
}

void	move_pac_follow_move_xy_2(t_data *d, t_pac *pac)
{
	if (pac->status == RUN)
	{
		pac->dx += 125 * pac->move_dx;
		pac->dy += 125 * pac->move_dy;
	}
	if (pac->status == GO_BACK)
	{
		while (pac->dx % 500)
			pac->dx -= 125 * pac->move_dx;
		while (pac->dy % 500)
			pac->dy -= 125 * pac->move_dy;
		pac->dx += 500 * pac->move_dx;
		pac->dy += 500 * pac->move_dy;
	}
	if (pac->dx % 1000 == 0)
		pac->x = pac->dx / 1000;
	if (pac->dy % 1000 == 0)
		pac->y = pac->dy / 1000;
	d->tmp42 = 0;
}

void	move_pac_follow_move_xy(t_data *d, t_pac *pac)
{
	if (pac->status == CHASE && \
		d->map_pellet_og[pac->dy / 1000][pac->dx / 1000] == 'S')
	{
		pac->dx += 125 * pac->move_dx;
		pac->dy += 125 * pac->move_dy;
	}
	else if (pac->status == CHASE)
	{
		while (pac->dx % 250)
			pac->dx -= 125 * pac->move_dx;
		while (pac->dy % 250)
			pac->dy -= 125 * pac->move_dy;
		pac->dx += 250 * pac->move_dx;
		pac->dy += 250 * pac->move_dy;
	}
	move_pac_follow_move_xy_2(d, pac);
}
