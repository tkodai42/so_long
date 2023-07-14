/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:01 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:21:48 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//======life=======

void	set_tex_pos_life(t_tex *tex)
{
	tex->start_y = 168;
	tex->end_y = 179;
	tex->start_x = 89;
	tex->end_x = 99;
}

void	put_life2(t_data *d, int pos)
{
	int		color;
	int		x;
	int		y;
	t_tex	tex;

	color = 0;
	set_tex_pos_life(&tex);
	y = 0;
	while (y + tex.start_y <= tex.end_y)
	{
		x = 0;
		while (x + tex.start_x <= tex.end_x)
		{
			color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
			if (color != 0)
				my_mlx_pixel_put(d, (x + 19) + pos * 16, \
					y + d->map_height * 8 + 2, color);
			x++;
		}
		y++;
	}
}

void	put_life(t_data *d)
{
	int		life;

	life = 0;
	while (life < d->life_stock && life < 5)
	{
		put_life2(d, life);
		life++;
	}
}
