/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:04:41 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 22:09:39 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ===== set tex =====
typedef struct s_tex_pos
{
	int		start_x;
	int		start_y;
}				t_tex_pos;

void	set_tex_pos(t_data *d, int tex_type, t_tex_pos *tex_pos)
{
	if (tex_type == TEX_GHOST)
	{
		tex_pos->start_x = 6 + 80;
		tex_pos->start_y = 86;
	}
	if (tex_type == TEX_PAC)
	{
		tex_pos->start_x = 6;
		tex_pos->start_y = 5;
	}
	if (tex_type == TEX_FRUITS)
	{
		tex_pos->start_x = 174;
		tex_pos->start_y = 166;
	}
	if (tex_type == TEX_EXIT)
	{
		tex_pos->start_x = 6;
		tex_pos->start_y = 166;
	}
	d->tmp42 = 0;
}

/*
void	set_tex_pos(t_data *d, int tex_type, t_tex_pos *tex_pos)
{
	const int		interval = 10;

	if (tex_type == TEX_GHOST)
	{
		tex_pos->start_x = 6 + 20 * ((d->all_frame % \
					(8 * interval)) / interval);
		tex_pos->start_y = 86;
	}
	if (tex_type == TEX_PAC)
	{
		tex_pos->start_x = 6 + 20 * ((d->all_frame % \
					(3 * interval)) / interval);
		tex_pos->start_y = 5;
	}
	if (tex_type == TEX_FRUITS)
	{
		tex_pos->start_x = 174;
		tex_pos->start_y = 166;
	}
	if (tex_type == TEX_EXIT)
	{
		tex_pos->start_x = 6 + 20 * ((d->all_frame % \
					(4 * interval)) / interval);
		tex_pos->start_y = 166;
	}
}
*/

int	get_set_tex(t_data *d, int x, int y, t_tex_pos *tex_pos)
{
	int		ret_color;

	x = x * d->size / 16;
	y = y * d->size / 16;
	ret_color = get_tex_color(d, tex_pos->start_x + x, tex_pos->start_y + y);
	return (ret_color);
}

// === map ====

int	ret_map_color(t_data *d, int x, int y)
{
	int			cell;
	int			color;
	t_tex_pos	tex_pos;

	cell = d->map[y / (16 * d->size)][x / (16 * d->size)];
	if (cell == '1')
		set_tex_pos(d, TEX_GHOST, &tex_pos);
	else if (cell == 'C')
		set_tex_pos(d, TEX_FRUITS, &tex_pos);
	else if (cell == 'E')
		set_tex_pos(d, TEX_EXIT, &tex_pos);
	if (cell == '0')
		color = BLACK;
	else
		color = get_set_tex(d, x % (16 * d->size),
				y % (16 * d->size), &tex_pos);
	return (color);
}

void	put_map(t_data *d)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < d->height)
	{
		x = 0;
		while (x < d->width)
		{
			color = ret_map_color(d, x, y);
			my_mlx_pixel_put(d, x, y, color);
			x++;
		}
		y++;
	}
}

// ==== put ====
void	put_player(t_data *d)
{
	int			x;
	int			y;
	int			size;
	int			color;
	t_tex_pos	tex_pos;

	y = 0;
	size = 16 * d->size;
	set_tex_pos(d, TEX_PAC, &tex_pos);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			color = get_set_tex(d, x, y, &tex_pos);
			my_mlx_pixel_put(d, d->x_pos * size + x,
				d->y_pos * size + y, color);
			x++;
		}
		y++;
	}
}
