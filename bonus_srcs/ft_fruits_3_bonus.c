/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fruits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:42:10 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:37:54 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ret_fruits_score(int stage)
{
	if (stage <= 0)
		return (100);
	if (stage <= 1)
		return (300);
	if (stage <= 3)
		return (500);
	if (stage <= 5)
		return (700);
	if (stage <= 7)
		return (1000);
	if (stage <= 9)
		return (2000);
	if (stage <= 11)
		return (3000);
	return (5000);
}

int	is_contact(int x1, int y1, int x2, int y2)
{
	int		a;
	int		b;

	a = abs(x1 - x2);
	b = abs(y1 - y2);
	return (sqrt(a * a + b * b) < 10);
}

void	set_tex_map_fruits(t_data *d, t_tex *tex, int pos)
{
	int		pos2;

	pos2 = 0;
	d->tmp42 = 0;
	if (pos >= 4)
	{
		pos2 = 1;
		pos += -4;
	}
	tex->start_y = 166 + pos * 20;
	tex->end_y = 182 + pos * 20;
	tex->start_x = 170 + 41 * pos2;
	tex->end_x = 194 + 41 * pos2;
}

void	put_fruits_map2_2(t_data *d, t_fruits *fruits)
{
	if (is_contact(8 * d->pac_mine.dx / 1000, 8 * d->pac_mine.dy / 1000, \
		fruits->dx_dist, fruits->dy_dist))
	{
		fruits->put_mode = FRUITS_TAKEN;
		if (d->game_set == 0)
		{
			d->score += ret_fruits_score(d->stage_count);
			d->life_score += ret_fruits_score(d->stage_count);
			fruits->put_count = 100;
		}
	}
}

void	put_fruits_map2(t_data *d, t_fruits *fruits)
{
	t_tex	tex;
	int		color;
	int		x;
	int		y;

	set_tex_map_fruits(d, &tex, ret_fruits(d->stage_count));
	y = 0;
	while (y + tex.start_y <= tex.end_y)
	{
		x = 0;
		while (x + tex.start_x <= tex.end_x)
		{
			color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
			if (color)
				my_mlx_pixel_put(d, x + fruits->dx, y + fruits->dy, color);
			x++;
		}
		y++;
	}
	put_fruits_map2_2(d, fruits);
}
