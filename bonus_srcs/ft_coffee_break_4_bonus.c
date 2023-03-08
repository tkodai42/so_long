/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:13:17 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:36:08 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_inside_window(t_data *d, int x, int y)
{
	if (x < 0 || d->width <= x)
		return (0);
	if (y < 0 || d->height <= y)
		return (0);
	return (1);
}

void	put_cb_pac2(t_data *d, t_pac *pac)
{
	t_tex	tex;
	int		tmp_x;
	int		tmp_y;

	tex.x = 0;
	tex.y = 0;
	set_anime_tex(d, pac, &tex);
	while (tex.y < 16)
	{
		tex.x = 0;
		while (tex.x < 16)
		{
			set_anime_color(d, &tex);
			tmp_x = tex.x - 4 + (double)pac->dx / 1000 * 8;
			tmp_y = tex.y - 4 + d->cb.add_y + (double)pac->dy / 1000 * 8;
			if (is_inside_window(d, tmp_x, tmp_y) == 1 && tex.color)
				my_mlx_pixel_put(d, tmp_x, tmp_y, tex.color);
			tex.x++;
		}
		tex.y++;
	}
}
