/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dotmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:12:36 by tkodai            #+#    #+#             */
/*   Updated: 2021/12/24 21:38:02 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_normal_map(t_data *d, int x, int y, int rate)
{
	if (d->dotmap[y][x] == BLUE && d->game_set_count / 3 >= 5)
	{
		if (rate > 6)
			my_mlx_pixel_put(d, x, y, BLUE);
		else
			my_mlx_pixel_put(d, x, y, WHITE);
	}
	else if (d->dotmap[y][x] == PINK && d->game_set_count / 3 >= 5)
		my_mlx_pixel_put(d, x, y, BLACK);
	else
		my_mlx_pixel_put(d, x, y, d->dotmap[y][x]);
}

void	madness_map2(t_data *d, int x, int y)
{
	int		rate;
	int		time;

	rate = d->all_frame % 100 / 2 + 5;
	//time = (d->all_frame + x + y) % (7 * rate) / rate;
	time = (x + y + d->all_frame) % (6 * 14) / 14;
	if (d->dotmap[y][x] == BLUE)
	{
		/*if (time == 0)
			my_mlx_pixel_put(d, x, y, 0xFF0000);
		if (time == 1)
			my_mlx_pixel_put(d, x, y, 0xFFA500);
		if (time == 2)
			my_mlx_pixel_put(d, x, y, 0xFFFF00);
		if (time == 3)
			my_mlx_pixel_put(d, x, y, 0x008000);
		if (time == 4)
			my_mlx_pixel_put(d, x, y, 0x00FFFF);
		if (time == 5)
			my_mlx_pixel_put(d, x, y, 0x0000FF);
		if (time == 6)
			my_mlx_pixel_put(d, x, y, 0x800080);*/
		if (time == 0)
			my_mlx_pixel_put(d, x, y, 0xb51802);
		if (time == 1)
			my_mlx_pixel_put(d, x, y, 0x05933a);
		if (time == 2)
			my_mlx_pixel_put(d, x, y, 0xb51802);
		if (time == 3)
			my_mlx_pixel_put(d, x, y, 0x05933a);
		if (time == 4)
			my_mlx_pixel_put(d, x, y, 0xb51802);
		if (time == 5)
			my_mlx_pixel_put(d, x, y, 0x05933a);
		if (time == 6)
			my_mlx_pixel_put(d, x, y, 0xb51802);
	}
	else
		my_mlx_pixel_put(d, x, y, d->dotmap[y][x]);
}

void	madness_map(t_data *d)
{
	int		x;
	int		y;
	int		rate;

	rate = d->all_frame % 10;
	rate = d->game_set_count % 10;
	y = 0;
	while (y < d->map_height * 8)
	{
		x = 0;
		while (x < d->map_width * 8)
		{
			if (d->pellet_num == 0 && d->game_set_count / 3 >= 5)
			{
				put_normal_map(d, x, y, rate);
			}
			else
				madness_map2(d, x, y);
			x++;
		}
		y++;
	}
}

void	ft_put_dotmap(t_data *d)
{
	int		rate;
	int		x;
	int		y;

	rate = d->all_frame % 12;
	rate = (d->game_set_count + 4) % 12;
	//if (d->madness)
	if (1)
	{
		madness_map(d);
		return ;
	}
	y = 0;
	while (y < d->map_height * 8)
	{
		x = 0;
		while (x < d->map_width * 8)
		{
			if (d->pellet_num == 0)
				put_normal_map(d, x, y, rate);
			else
				my_mlx_pixel_put(d, x, y, d->dotmap[y][x]);
			x++;
		}
		y++;
	}
}
