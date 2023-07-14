/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixelputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:23:35 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/11 21:26:25 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_mlx_pixel_put_og(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->img_addr + (y * d->img_line_lenght + x * \
		(d->img_bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_xxx(t_data *d, int x, int y, int color)
{
	char	*dst;

	if (x >= d->width || x < 0)
		return ;
	dst = d->img_addr + (y * d->img_line_lenght + x * \
		(d->img_bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	int		t_y;
	int		t_x;

	y += 3 * 8;
	t_y = 0;
	while (t_y < d->size)
	{
		t_x = 0;
		if (y * d->size + t_y > d->height)
			break ;
		while (t_x < d->size)
		{
			if (x * d->size + t_x > d->width)
				break ;
			my_mlx_pixel_put_xxx(d, x * d->size + t_x, y * \
				d->size + t_y, color);
			t_x++;
		}
		t_y++;
	}
}

void	real_clear(t_data *d)
{
	int		x;
	int		y;

	y = 0;
	while (y < d->height)
	{
		x = 0;
		while (x < d->width)
		{
			my_mlx_pixel_put_og(d, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	ft_clear_window(t_data *d)
{
	d->clear_flag = 1;
}
