/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:01 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/11 16:09:21 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	my_mlx_pixel_put_xxx_top(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->img_addr + (y * d->img_line_lenght + \
			x * (d->img_bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_top(t_data *d, int x, int y, int color)
{
	int		size;
	int		t_y;
	int		t_x;

	size = d->size;
	t_y = 0;
	while (t_y < size)
	{
		t_x = 0;
		while (t_x < size)
		{
			if (x * size + t_x > d->width)
				break ;
			my_mlx_pixel_put_xxx_top(d, x * size + t_x, y * size + t_y, color);
			t_x++;
		}
		if (y * size + t_y > d->height)
			break ;
		t_y++;
	}
}

void	hide_one_up(t_data *d)
{
	int		x;
	int		y;

	if (d->all_frame % 16 >= 8)
	{
		x = 26;
		y = 0;
		while (y <= 7)
		{
			x = 26;
			while (x <= 48)
			{
				my_mlx_pixel_put_top(d, x, y, BLACK);
				x++;
			}
			y++;
		}
	}
}

//======life=======

void	fix_move_count(t_data *d)
{
	while (d->move_count_d >= 1000)
	{
		d->move_count_d -= 1000;
		d->move_count++;
	}
}

void	put_score(t_data *d)
{
	put_score_logo(d);
	fix_move_count(d);
	if (d->move_count_is_valid == 0)
		put_score_num(d);
	put_high_score_num(d);
	hide_one_up(d);
	put_life(d);
}
