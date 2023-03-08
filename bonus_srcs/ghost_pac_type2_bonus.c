/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_pac_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:16:29 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:20:19 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	get_tag2(t_data *d, t_pac *pac)
{
	if (pac->status == GO_BACK && \
		pac->dy == (d->nest.door1_y - 1) * 1000 && \
		abs(pac->dx - (d->nest.door1_x * 1000 + 1000)) <= 5000)
	{
		pac->tag_x = d->pac_mine.x;
		pac->tag_y = d->pac_mine.y;
		pac->status = CHASE;
		pac->status = NEST;
		pac->nest_status = INTO;
		return ;
	}
	if (pac->status == GO_BACK)
	{
		pac->tag_x = d->nest.door1_x;
		pac->tag_y = d->nest.door1_y - 1;
		return ;
	}
}

void	move_ghost_killed_2(t_data *d, t_pac *pac)
{
	int	tmp_score;

	pac->tmp42 = 0;
	tmp_score = 0;
	if (d->eat_streak == 1)
		tmp_score = 200;
	if (d->eat_streak == 2)
		tmp_score = 400;
	if (d->eat_streak == 3)
		tmp_score = 800;
	if (d->eat_streak == 4)
		tmp_score = 1600;
	d->score += tmp_score;
	d->life_score += tmp_score;
}

void	move_ghost_killed(t_data *d, t_pac *pac)
{
	pac->nest_status = INTO;
	pac->tag_x = d->nest.door1_x;
	pac->tag_y = d->nest.door1_y - 1;
	while (pac->dx % 500 != 0)
		pac->dx += 125 * pac->move_dx;
	while (pac->dy % 500 != 0)
		pac->dy += 125 * pac->move_dy;
	if (pac->dx % 1000 == 0)
		pac->dx = pac->x * 1000;
	if (pac->dy % 1000 == 0)
		pac->dy = pac->y * 1000;
	pac->blue_time = 0;
	pac->status = GO_BACK;
	d->eat_stop_count = 20;
	pac->vanish_count = 20;
	d->eat_streak++;
	if (d->game_set == 0)
	{
		move_ghost_killed_2(d, pac);
	}
}

void	move_ghost_type2_2(t_data *d, t_pac *pac)
{
	if (pac->status == RUN && abs(pac->dx - d->pac_mine.dx) + \
			abs(pac->dy - d->pac_mine.dy) <= 1500)
	{
		move_ghost_killed(d, pac);
		return ;
	}
	if ((pac->move_dx + pac->move_dy != 0) && pac_on_branch(d, pac) == 0)
	{
		move_pac_follow_move_xy(d, pac);
		return ;
	}
	pac->dir_x = pac->move_dx;
	pac->dir_y = pac->move_dy;
	pac->move_dx = 0;
	pac->move_dy = 0;
	get_target(d, pac);
	get_tag2(d, pac);
	set_move_dir_ver2(d, pac);
	move_pac_follow_move_xy(d, pac);
}

void	move_ghost_type2(t_data *d, t_pac *pac)
{
	if (d->eat_stop_count && pac->vanish_count == 0 && pac->status \
		!= GO_BACK && (!(pac->status == NEST && pac->nest_status == INTO)))
		return ;
	if (pac->vanish_count)
		return ;
	if (pac->status == NEST)
	{
		ft_nest(d, pac);
		return ;
	}
	if (pac->status == CHASE && abs(pac->dx - d->pac_mine.dx) + \
			abs(pac->dy - d->pac_mine.dy) <= 1500)
	{
		if (d->game_set == 0)
			write_high_score(d);
		d->game_set = 1;
	}	
	move_ghost_type2_2(d, pac);
}
