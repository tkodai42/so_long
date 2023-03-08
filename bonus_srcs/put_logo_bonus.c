/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_logo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:33:10 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/12 12:32:26 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

typedef struct s_logo
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
}				t_logo;

void	put_end_logo(t_data *d)
{
	int		color;
	t_logo	logo;
	int		x;
	int		y;

	logo.start_y = 196;
	logo.end_y = 203;
	logo.start_x = 17;
	logo.end_x = 96;
	d->stage_frame = DEFAULT_SPEED;
	y = 0;
	while (y + logo.start_y <= logo.end_y)
	{
		x = 0;
		while (x + logo.start_x <= logo.end_x)
		{
			color = get_tex_color(d, x + logo.start_x, y + logo.start_y);
			if (color != 0)
				my_mlx_pixel_put(d, (d->nest.door1_x - 4) * 8 + x, \
					(d->nest.door1_y + 5) * 8 + y, color);
			x++;
		}
		y++;
	}
}

void	put_start_logo(t_data *d)
{
	int		color;
	t_logo	logo;
	int		x;
	int		y;

	color = 0;
	logo.start_y = 6;
	logo.end_y = 13;
	logo.start_x = 205;
	logo.end_x = 253;
	y = 0;
	while (y + logo.start_y <= logo.end_y)
	{
		x = 0;
		while (x + logo.start_x <= logo.end_x)
		{
			color = get_tex_color(d, x + logo.start_x, y + logo.start_y);
			if (color != 0)
				my_mlx_pixel_put(d, (d->nest.door1_x - 2) * 8 + x, \
					(d->nest.door1_y + 5) * 8 + y, color);
			x++;
		}
		y++;
	}
}
