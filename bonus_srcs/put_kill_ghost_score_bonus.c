/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_kill_ghost_score.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:50:06 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/11 17:09:01 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_kill_ghost_score(t_data *d)
{
	t_tex	tex;
	int		x;
	int		y;
	int		color;

	if (d->eat_streak >= 5)
		d->eat_streak = 4;
	tex.start_x = 6 + (d->eat_streak - 1) * 20;
	tex.end_x = 22 + (d->eat_streak - 1) * 20;
	tex.start_y = 230;
	tex.end_y = 237;
	y = 0;
	while (y + tex.start_y <= tex.end_y)
	{
		x = 0;
		while (x + tex.start_x <= tex.end_x)
		{
			color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
			if (color != 0)
				my_mlx_pixel_put(d, x - 4 + (double)d->pac_mine.dx / \
					1000 * 8, y + (double)d->pac_mine.dy / 1000 * 8, color);
			x++;
		}
		y++;
	}
}
