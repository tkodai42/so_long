/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move_dir_ver2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:44:33 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/12 20:53:55 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	search_dist(t_data *d, t_pac *pac, int x, int y)
{
	int		tmp_dist;
	int		a;
	int		b;
	char	cell;

	cell = d->map_pellet_og[pac->y + y][pac->x + x];
	if (pac->dir_x == x * -1 && pac->dir_y == y * -1)
		return ;
	if (d->map[pac->y + y][pac->x + x] == '1')
		return ;
	if (y == -1 && (cell == 'z' || cell == 'Z'))
	{
		return ;
	}
	a = abs(pac->dx + x * 1000 - pac->tag_x * 1000);
	b = abs(pac->dy + y * 1000 - pac->tag_y * 1000);
	tmp_dist = sqrt(a * a + b * b);
	if (tmp_dist < pac->dist)
	{
		pac->dist = tmp_dist;
		pac->move_dx = x;
		pac->move_dy = y;
	}
}

void	set_move_dir_ver2(t_data *d, t_pac *pac)
{
	pac->dist = 100000000;
	pac->move_dx = 0;
	pac->move_dy = 0;
	search_dist(d, pac, 1, 0);
	search_dist(d, pac, -1, 0);
	search_dist(d, pac, 0, 1);
	search_dist(d, pac, 0, -1);
}

void	show_target(t_data *d, t_pac *pac, int color)
{
	int		tmp_x;
	int		tmp_y;
	int		y;
	int		x;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if (x < 2 || 6 <= x || y < 2 || 6 <= y)
			{
				tmp_x = x + pac->tag_x * 8;
				tmp_y = y + pac->tag_y * 8;
				if (0 <= tmp_x && tmp_x < d->width && 0 <= tmp_y
					&& tmp_y < d->height)
					my_mlx_pixel_put(d, tmp_x, tmp_y, color);
			}
			x++;
		}
		y++;
	}
}
