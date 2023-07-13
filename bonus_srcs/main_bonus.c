/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:06:46 by tkodai            #+#    #+#             */
/*   Updated: 2021/12/29 20:49:54 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_solong_loop(t_data *d)
{
	int	tmp;

	if (d->width > 16384 + 100 || d->height > 16384 + 100)
	{
		printf("Error\nthe maximum allowed size => 16384\n");
		exit(1);
	}
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width, d->height, "so_long");
	if (d->win_ptr == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	d->img_ptr = mlx_new_image(d->mlx_ptr, d->width, d->height);
	d->img_addr = mlx_get_data_addr(d->img_ptr, &d->img_bit_per_pixel, \
		&d->img_line_lenght, &tmp);
	mlx_hook(d->win_ptr, 2, 1L << 0, ft_key_pressed, d);
	mlx_hook(d->win_ptr, 3, 1L << 1, ft_key_released, d);
	mlx_hook(d->win_ptr, EVENT_EXIT, 1L << 0, ft_error, d);
	mlx_loop_hook(d->mlx_ptr, ft_reflect_key, d);
	mlx_loop(d->mlx_ptr);
}

void	ft_solong(t_data *d)
{
	d->mlx_ptr = mlx_init();
	ft_solong_init_1(d);
	ft_solong_init_2(d);
	ft_solong_init_3(d);
	read_high_score(d);
	init_fruits(d, &(d->fruits));
	d->move_count = 0;
	d->move_count_d = 0;
	d->move_count_is_valid = 0;
	d->cb.coffee = 0;
	init_coffee(d);
	ft_read_xpm(d);
	ft_solong_loop(d);
}

static void	check_size(int num)
{
	if (num <= 0 || 100 < num)
	{
		printf("Error\nInvalid window size: argv\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	d;

	d.file_name = argv[1];
	if (argc == 3)
	{
		d.size = *argv[2] - 48;
		check_size(d.size);
		d.size_set = 1;
	}
	else
	{
		d.size = SIZE;
		d.size_set = 0;
	}
	ft_read_file(&d);
	ft_generate_dotmap(&d);
	ft_solong(&d);
	return (0);
}
