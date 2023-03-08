/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fruits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:42:10 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:21:25 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ret_fruits(int stage)
{
	if (stage <= 0)
		return (FRUITS_0);
	if (stage <= 1)
		return (FRUITS_1);
	if (stage <= 3)
		return (FRUITS_2);
	if (stage <= 5)
		return (FRUITS_3);
	if (stage <= 7)
		return (FRUITS_4);
	if (stage <= 9)
		return (FRUITS_5);
	if (stage <= 11)
		return (FRUITS_6);
	return (FRUITS_7);
}

void	set_tex_map_fruits_score(t_tex *tex, int pos)
{
	tex->start_y = 6 + pos * 20;
	tex->end_y = 22 + pos * 20;
	tex->start_x = 170;
	tex->end_x = 194;
}

void	put_fruits_map_taken(t_data *d, t_fruits *fruits)
{
	t_tex	tex;
	int		color;
	int		x;
	int		y;

	set_tex_map_fruits_score(&tex, ret_fruits(d->stage_count));
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
}

void	put_fruits_map(t_data *d, t_fruits *fruits)
{
	if (d->game_set != 0)
		return ;
	if (fruits->put_70 && d->pellet_num_og - 70 == d->pellet_num)
	{
		fruits->put_mode = FRUITS_APPEAR;
		fruits->put_count = 300;
		fruits->put_70 = 0;
	}
	if (fruits->put_140 && d->pellet_num_og - 140 == d->pellet_num)
	{
		fruits->put_140 = 0;
		fruits->put_count = 300;
		fruits->put_mode = FRUITS_APPEAR;
	}
	if (fruits->put_count)
		fruits->put_count--;
	if (fruits->put_count == 0)
		fruits->put_mode = FRUITS_HIDE;
	if (fruits->put_mode == FRUITS_HIDE)
		return ;
	if (fruits->put_mode == FRUITS_APPEAR)
		put_fruits_map2(d, fruits);
	else if (fruits->put_mode == FRUITS_TAKEN)
		put_fruits_map_taken(d, fruits);
}

void	ft_fruits(t_data *d)
{
	t_fruits	*fruits;

	fruits = &d->fruits;
	put_fruits_logo(d, fruits);
	put_fruits_map(d, fruits);
}
