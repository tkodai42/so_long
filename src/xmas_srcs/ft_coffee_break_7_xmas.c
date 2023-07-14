/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:13:17 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/14 16:14:27 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

int	ret_cb_logo_color_2(t_data *d, int x, int y, int num)
{
	int		color;

	x = x - d->cb.start_x2;
	y = y - d->cb.start_y2;
	x = d->xpm_width_c[num] * x / d->cb.logo_w2;
	y = d->xpm_height_c[num] * y / d->cb.logo_h2;
	color = get_tex_color3(d, x, y, num);
	return (color);
}

void	put_cb_logo_2(t_data *d, int type, int num)
{
	int		x;
	int		y;
	int		color;

	y = d->cb.start_y2;
	while (y < d->cb.end_y2)
	{
		x = d->cb.start_x2;
		while (x < d->cb.end_x2)
		{
			color = ret_cb_logo_color_2(d, x, y, num);
			if (type == 1 && is_black(d, x, y) && x < d->cb.valid_x)
				my_mlx_pixel_put_og(d, x, y, color);
			if (type == 2)
				my_mlx_pixel_put_og(d, x, y, color);
			x++;
		}
		y++;
	}
}
