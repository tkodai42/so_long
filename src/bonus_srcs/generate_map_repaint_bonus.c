/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_repaint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:22:48 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/16 14:04:38 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	repaint_map_color(t_data *d, int w, int h)
{
	int		color;

	color = d->dotmap[h][w];
	if (color == BLACK)
		return ;
	if (color == BLUE && d->repaint)
	{
		d->dotmap[h][w] = BLUE;
		if (d->map_pellet_og[h / 8][w / 8] == 'W')
			d->dotmap[h][w] = WHITE;
		if (d->map_pellet_og[h / 8][w / 8] == 'N')
			d->dotmap[h][w] = WHITE;
	}
}

void	repaint_map(t_data *d)
{
	int		w;
	int		h;

	h = 0;
	while (h < d->map_height * 8)
	{
		w = 0;
		while (w < d->map_width * 8)
		{
			repaint_map_color(d, w, h);
			w++;
		}
		h++;
	}
}
