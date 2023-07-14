/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:04:41 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 20:49:47 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ===== init ====
void	init_data(t_data *d)
{
	d->size = SIZE;
	d->all_frame = 0;
	d->move_count = 0;
	d->colect_num = 0;
	d->check_player = 0;
	d->check_escape = 0;
	d->check_line_len = 0;
}

void	ft_so_long_loop(t_data *d)
{
	int		tmp;

	d->img_ptr = mlx_new_image(d->mlx_ptr, d->width, d->height);
	d->img_addr = mlx_get_data_addr(d->img_ptr, &d->img_bit_per_pixel,
			&d->img_line_lenght, &tmp);
	mlx_hook(d->win_ptr, 2, 1L << 0, ft_key_pressed, d);
	mlx_hook(d->win_ptr, EVENT_EXIT, 1L << 0, ft_xxx, d);
	mlx_loop_hook(d->mlx_ptr, ft_key_reflect, d);
	mlx_loop(d->mlx_ptr);
}

void	is_valid_size(t_data *d)
{
	int		max_width;
	int		max_height;

	mlx_get_screen_size(d->mlx_ptr, &max_width, & max_height);
	if (d->width >= max_width || d->height > max_height)
		put_error(d, "invalid map: screen size");
}

void	ft_solong(t_data *d)
{
	d->width = d->map_width * 16 * d->size;
	d->height = d->map_height * 16 * d->size;
	d->mlx_ptr = mlx_init();
	is_valid_size(d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width, d->height, "so_long");
	ft_read_xpm(d);
	ft_so_long_loop(d);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc != 2)
		put_error(&d, "invalid arg: argc");
	d.file_name = argv[1];
	init_data(&d);
	ft_read_file(&d);
	ft_solong(&d);
}
