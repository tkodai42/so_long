/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fruits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:42:10 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:37:35 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

void	init_fruits(t_data *d, t_fruits *fruits)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		fruits->stack[i] = FRUITS_NONE;
		i++;
	}
	fruits->stack[0] = FRUITS_0;
	fruits->stack_num = 0;
	fruits->dx = d->nest.door1_x * 8 - 4;
	fruits->dy = (d->nest.door1_y + 4) * 8 + 4;
	fruits->dy_dist = fruits->dy + 1 * 8;
	fruits->dx_dist = fruits->dx + 1 * 8;
	fruits->put_mode = FRUITS_HIDE;
	fruits->put_count = 0;
	fruits->put_70 = 1;
	fruits->put_140 = 1;
}

void	level_up_fruits(t_data *d, t_fruits *fruits)
{
	int		i;

	if (fruits->stack_num >= 6)
	{
		i = 0;
		while (i < 6)
		{
			fruits->stack[i] = fruits->stack[i + 1];
			i++;
		}
		fruits->stack[i] = ret_fruits(d->stage_count);
	}
	else
	{
		fruits->stack_num++;
		fruits->stack[fruits->stack_num] = ret_fruits(d->stage_count);
	}
	fruits->put_mode = 0;
	fruits->put_count = 0;
	fruits->put_70 = 1;
	fruits->put_140 = 1;
}

// ==== logo ====
void	set_tex_pos_fruits(t_data *d, t_tex *tex, int pos)
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
	tex->start_x = 174 + 41 * pos2;
	tex->end_x = 190 + 41 * pos2;
}

void	del_fruits(t_data *d, int *i)
{
	int		x;
	int		y;

	*i = 0;
	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < d->map_width * 8)
		{
			my_mlx_pixel_put(d, x, y + d->map_height * 8, BLACK);
			x++;
		}
		y++;
	}	
}

void	put_fruits_logo(t_data *d, t_fruits *fruits)
{
	int		i;
	int		color;
	int		x;
	int		y;
	t_tex	tex;

	del_fruits(d, &i);
	while (i <= fruits->stack_num && i < 7)
	{
		set_tex_pos_fruits(d, &tex, fruits->stack[i]);
		y = 0;
		while (y + tex.start_y <= tex.end_y)
		{
			x = 0;
			while (x + tex.start_x <= tex.end_x)
			{
				color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
				my_mlx_pixel_put(d, (x + 192) - i * 16, y + d->map_height * 8, \
						color);
				x++;
			}
			y++;
		}	
		i++;
	}
}
