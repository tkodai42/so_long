/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:27:29 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:36:56 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

void	set_anime_color_expand(t_data *d, t_pac *pac, t_tex *tex)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = tex->x;
	tmp_y = tex->y;
	tex->x /= 5;
	tex->y /= 5;
	set_anime_color(d, tex);
	if (tex->color == 0xFB0007)
		tex->color = pac->color;
	tex->x = tmp_x;
	tex->y = tmp_y;
}

void	get_valid_x(t_data *d, t_pac *pac)
{
	if (pac->cb_tex == 3)
		d->cb.valid_x = ((double)pac->dx / 1000 * 8 + 3 * 5) * d->size;
	else
		d->cb.valid_x = ((double)pac->dx / 1000 * 8 + 8 * 5) * d->size;
}

void	put_cb_pac6(t_data *d, t_pac *pac)
{
	t_tex	tex;
	int		tmp_x;
	int		tmp_y;

	tex.x = 0;
	tex.y = 0;
	set_anime_tex(d, pac, &tex);
	while (tex.y < 48 + 16 + 16)
	{
		tex.x = 0;
		while (tex.x < 48 + 16 + 16)
		{
			set_anime_color_expand(d, pac, &tex);
			tmp_x = 48 + 16 + 16 - (tex.x - 4) + (double)pac->dx / 1000 * 8;
			tmp_y = tex.y - 24 - 18 + (double)pac->dy / 1000 * 8;
			if (is_inside_window(d, tmp_x, tmp_y) == 1 && tex.color)
				my_mlx_pixel_put(d, tmp_x, tmp_y, tex.color);
			tex.x++;
		}
		tex.y++;
	}
	get_valid_x(d, pac);
	if (pac->type == ANIME_GHOST1)
		put_cb_logo_2(d, 1, pac->cb_tex);
}
