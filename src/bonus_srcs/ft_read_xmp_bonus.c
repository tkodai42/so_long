/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_xmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:29:58 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/14 16:13:11 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_just_code(t_data *d, int i, char *filename)
{
	void	*img;
	int		tmp;

	img = mlx_xpm_file_to_image(d->mlx_ptr, filename, \
			&d->xpm_width_c[i], &d->xpm_height_c[i]);
	d->xpm_addr_c[i] = mlx_get_data_addr(img, &d->bits_per_pixel_c[i], \
			&d->line_len_c[i], &tmp);
}

void	open_file_tex(t_data *d)
{
	void	*img;
	int		tmp;

	img = mlx_xpm_file_to_image(d->mlx_ptr, "./tex/pacman.xpm", \
			&d->xpm_width, &d->xpm_height);
	d->xpm_addr = mlx_get_data_addr(img, &d->bits_per_pixel, \
			&d->line_len, &tmp);
	img = mlx_xpm_file_to_image(d->mlx_ptr, "./tex/42tokyo.xpm", \
			&d->xpm_width2, &d->xpm_height2);
	d->xpm_addr2 = mlx_get_data_addr(img, &d->bits_per_pixel2, \
			&d->line_len2, &tmp);
	open_just_code(d, 0, "./tex/justcode1.xpm");
	open_just_code(d, 1, "./tex/justcode2.xpm");
	open_just_code(d, 2, "./tex/justcode3.xpm");
	open_just_code(d, 3, "./tex/justcode4.xpm");
}

void	ft_read_xpm(t_data *d)
{
	open_file_tex(d);
}
