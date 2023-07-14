/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:01 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/11 16:07:56 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	del_logo(t_data *d, t_tex tex)
{
	int		x;
	int		y;

	y = 0;
	while (y + tex.start_y <= tex.end_y)
	{
		x = 0;
		while (x + tex.start_x <= tex.end_x)
		{
			my_mlx_pixel_put_top(d, x, y, BLACK);
			x++;
		}
		y++;
	}
}

static void	set_put_score_logo_pos(t_tex *tex, int *y, int *color)
{
	tex->start_x = 162;
	tex->start_y = 268;
	tex->end_x = 314;
	tex->end_y = 284;
	*y = 0;
	*color = 0;
}

void	put_score_logo(t_data *d)
{
	int		color;
	int		x;
	int		y;
	t_tex	tex;

	set_put_score_logo_pos(&tex, &y, &color);
	if (d->move_count_is_valid)
	{
		del_logo(d, tex);
		return ;
	}
	while (y + tex.start_y <= tex.end_y)
	{
		x = 0;
		while (x + tex.start_x <= tex.end_x)
		{
			color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
			if (color != 0)
				color = WHITE;
			my_mlx_pixel_put_top(d, x, y, color);
			x++;
		}
		y++;
	}
}
//188 - 26
