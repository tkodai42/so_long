/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:04:41 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/04 19:48:29 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dest;

	dest = d->img_addr + (y * d->img_line_lenght + x * \
			(d->img_bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	open_file_tex(t_data *d)
{
	void	*img;
	int		tmp;

	img = mlx_xpm_file_to_image(d->mlx_ptr, "./tex/pacman.xpm",
			&d->xpm_width, &d->xpm_height);
	d->xpm_addr = mlx_get_data_addr(img, &d->bits_per_pixel,
			&d->line_len, &tmp);
}

void	ft_read_xpm(t_data *d)
{
	open_file_tex(d);
}

int	get_tex_color(t_data *d, int x, int y)
{
	int	color;

	color = *(unsigned int *)(d->xpm_addr + y * d->line_len + x * 4);
	return (color);
}
