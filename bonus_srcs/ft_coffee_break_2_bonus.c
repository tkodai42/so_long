/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coffee_break.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:13:17 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:36:28 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_black(t_data *d, int x, int y)
{
	char	*dst;

	dst = d->img_addr + (y * d->img_line_lenght + x * \
		(d->img_bit_per_pixel / 8));
	if (*(unsigned int *)dst == BLACK)
		return (1);
	return (0);
}

void	put_cb_pac4(t_data *d, t_pac *pac)
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
		while (tex.x < 28)
		{
			set_anime_color(d, &tex);
			tmp_x = tex.x - 4 + (double)pac->dx / 1000 * 8;
			tmp_y = tex.y - 4 + d->cb.add_y + (double)pac->dy / 1000 * 8;
			if (is_inside_window(d, tmp_x, tmp_y) && tex.color && \
				is_black(d, tmp_x * d->size, (tmp_y + 3 * 8) * d->size))
				my_mlx_pixel_put(d, tmp_x, tmp_y, tex.color);
			tex.x++;
		}
		tex.y++;
	}
}

int	ret_cb_logo_color(t_data *d, int x, int y)
{
	int		color;

	x = x - d->cb.start_x;
	y = y - d->cb.start_y;
	x = d->xpm_width2 * x / d->cb.logo_w;
	y = d->xpm_height2 * y / d->cb.logo_h;
	color = get_tex_color2(d, x, y);
	return (color);
}

void	put_cb_logo(t_data *d, int type)
{
	int		x;
	int		y;
	int		color;

	y = d->cb.start_y;
	while (y < d->cb.end_y)
	{
		x = d->cb.start_x;
		while (x < d->cb.end_x)
		{
			color = ret_cb_logo_color(d, x, y);
			if (type == 1 && is_black(d, x, y) && x < d->cb.valid_x)
				my_mlx_pixel_put_og(d, x, y, color);
			if (type == 2)
				my_mlx_pixel_put_og(d, x, y, color);
			x++;
		}
		y++;
	}
}

void	put_cb_pac3(t_data *d, t_pac *pac)
{
	t_tex	tex;
	int		tmp_x;
	int		tmp_y;

	tex.x = 0;
	tex.y = 0;
	set_anime_tex(d, pac, &tex);
	while (tex.y < 32)
	{
		tex.x = 0;
		while (tex.x < 32)
		{
			set_anime_color(d, &tex);
			tmp_x = tex.x - 4 + (double)pac->dx / 1000 * 8;
			tmp_y = tex.y - 14 + (double)pac->dy / 1000 * 8;
			if (is_inside_window(d, tmp_x, tmp_y) == 1)
				my_mlx_pixel_put(d, tmp_x, tmp_y, tex.color);
			tex.x++;
		}
		tex.y++;
	}
	d->cb.valid_x = ((double)pac->dx / 1000 * 8 - 4 + 12) * d->size;
	if (pac->type == ANIME_PAC_BIG)
		put_cb_logo(d, 1);
}
