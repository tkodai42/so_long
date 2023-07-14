/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_pellet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:05:29 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:27:04 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_eat_pellet_X2(t_data *d, t_pac *pac)
{
	if (pac->status != GO_BACK)
		pac->blue_time = d->eat_std_time;
	if (pac->status == CHASE || pac->status == RUN)
	{
		pac->status = RUN;
		pac->blue_time = d->eat_std_time;
		if (pac_on_branch(d, pac) == 0)
		{
			pac->move_dx *= -1;
			pac->move_dy *= -1;
		}
	}
}

void	ft_eat_pellet_X(t_data *d)
{
	d->eat_std_time = EAT_TIME - d->stage_count * EAT_TIME / 18;
	if (d->eat_std_time <= 0)
		d->eat_std_time = 1;
	d->eat_time = d->eat_std_time;
	d->eat_streak = 0;
	if (d->game_set == 0)
	{
		d->score += 50;
		d->life_score += 50;
		d->pellet_num--;
		d->map_pellet[d->pac_mine.y][d->pac_mine.x] = '1';
	}
	ft_eat_pellet_X2(d, &(d->pac_1));
	ft_eat_pellet_X2(d, &(d->pac_2));
	ft_eat_pellet_X2(d, &(d->pac_3));
	ft_eat_pellet_X2(d, &(d->pac_4));
}

void	ft_eat_pellet(t_data *d)
{
	char	pellet;

	pellet = d->map_pellet[d->pac_mine.y][d->pac_mine.x];
	if (pellet == 'X')
	{
		ft_eat_pellet_X(d);
	}
	if ((pellet == 'z' || pellet == 'C') && d->game_set == 0)
	{
		d->score += 10;
		d->life_score += 10;
		d->pellet_num--;
		d->map_pellet[d->pac_mine.y][d->pac_mine.x] = '1';
	}
	if (d->score > d->high_score)
		d->high_score = d->score;
	if (d->life_score >= 10000)
	{
		d->life_stock++;
		d->life_score -= 10000;
	}
	if (d->pellet_num == 0)
		d->game_set = 1;
}
