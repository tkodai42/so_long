/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cookie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:21:07 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/11 21:22:42 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_dot_2(t_data *d, int tab_x, int tab_y)
{
	int		x;
	int		y;

	y = 3;
	while (y < 5)
	{
		x = 3;
		while (x < 5)
		{
			my_mlx_pixel_put(d, x + tab_x * 8, y + tab_y * 8, TUMBLEWEED);
			x++;
		}
		y++;
	}
}

const char	g_power_cookie[8][8] = {{"00111100"},
								{"01111110"},
								{"11111111"},
								{"11111111"},
								{"11111111"},
								{"11111111"},
								{"01111110"},
								{"00111100"}};

void	put_dot_power(t_data *d, int tab_x, int tab_y)
{
	int		x;
	int		y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if (g_power_cookie[y][x] == '1')
				my_mlx_pixel_put(d, x + tab_x * 8, y + tab_y * 8, TUMBLEWEED);
			x++;
		}
		y++;
	}
}

void	put_dot(t_data *d)
{
	int		x;
	int		y;

	y = 0;
	while (y < d->map_height)
	{
		x = 0;
		while (x < d->map_width)
		{
			if (d->map_pellet[y][x] == 'C' || d->map_pellet[y][x] == 'z')
				put_dot_2(d, x, y);
			if (d->frame < 4 && d->map_pellet[y][x] == 'X')
				put_dot_power(d, x, y);
			x++;
		}
		y++;
	}
}
