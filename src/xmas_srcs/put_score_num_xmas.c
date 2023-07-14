/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:01 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:22:12 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

void	set_tex_pos_num(t_tex *tex, int num)
{
	tex->start_x = 17 + 10 * num;
	tex->end_x = tex->start_x + 7;
	tex->start_y = 186;
	tex->end_y = 193;
}

void	put_score_number(t_data *d, int num, int digit, int high)
{
	int		color;
	int		x;
	int		y;
	t_tex	tex;

	color = 0;
	set_tex_pos_num(&tex, num);
	y = 0;
	while (y + tex.start_y <= tex.end_y)
	{
		x = 0;
		while (x + tex.start_x <= tex.end_x)
		{
			color = get_tex_color(d, x + tex.start_x, y + tex.start_y);
			if (color != 0)
				color = WHITE;
			my_mlx_pixel_put_top(d, x + 41 + 80 * \
				high - 8 * digit, y + 9, color);
			x++;
		}
		y++;
	}
}

//digit 999999999 
//num   987654321
void	put_score_num(t_data *d)
{
	int	num;
	int	digit;

	num = d->score / 10;
	digit = 0;
	while (num > 9)
	{
		put_score_number(d, num % 10, digit, 0);
		digit++;
		num = num / 10;
	}
	put_score_number(d, num % 10, digit, 0);
}

void	put_high_score_num(t_data *d)
{
	int	num;
	int	digit;

	num = d->high_score / 10;
	digit = 0;
	if (d->move_count_is_valid)
		num = d->move_count;
	while (num > 9)
	{
		put_score_number(d, num % 10, digit, 1);
		digit++;
		num = num / 10;
	}
	put_score_number(d, num % 10, digit, 1);
}
