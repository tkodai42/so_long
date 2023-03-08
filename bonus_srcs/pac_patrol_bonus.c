/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_partol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:21:35 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/13 18:29:36 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	search_direction(t_data *d, t_pac *pac, int x, int y)
{
	int		tmp_dist;
	int		a;
	int		b;

	if (pac->dir_x == x * -1 && pac->dir_y == y * -1)
		return ;
	if (d->map[pac->y + y][pac->x + x] != '0')
		return ;
	a = abs(pac->dx + x * 600 - pac->home_pos_dx);
	b = abs(pac->dy + y * 1000 - pac->home_pos_dy);
	tmp_dist = sqrt(a * a + b * b);
	if (tmp_dist < pac->dist)
	{
		pac->dist = tmp_dist;
		pac->tag_x = pac->x + x;
		pac->tag_y = pac->y + y;
		pac->move_dx = x;
		pac->move_dy = y;
	}
}

void	pac_patrol(t_data *d, t_pac *pac)
{
	pac->dist = 10000000;
	pac->move_dx = 0;
	pac->move_dy = 0;
	search_direction(d, pac, 1, 0);
	search_direction(d, pac, -1, 0);
	search_direction(d, pac, 0, 1);
	search_direction(d, pac, 0, -1);
	if (pac->move_dx == 0 && pac->move_dy == 0)
	{
		pac->tag_x = pac->x + pac->dir_x * -1;
		pac->tag_y = pac->y + pac->dir_y * -1;
	}
	if (pac->dir_x == 0 && pac->dir_y == 0)
	{
		pac->tag_x = pac->x - 2;
		pac->tag_y = pac->y;
	}
}

void	get_target_patrol(t_data *d, t_pac *pac)
{
	pac_patrol(d, pac);
	if (pac->tag_y == pac->y && pac->tag_x == pac->x)
	{
		pac->tag_x = d->pac_mine.x;
		pac->tag_y = d->pac_mine.y;
	}
}
