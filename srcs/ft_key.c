/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:04:41 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/17 16:25:18 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ==== key ====
int	ft_key_reflect(t_data *d)
{
	d->all_frame++;
	if (d->all_frame > 1000000)
		d->all_frame = 0;
	put_map(d);
	put_player(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (0);
}

void	try_move(t_data *d, int x, int y)
{
	if (d->map[y][x] != '1')
	{
		d->move_count++;
		printf("\"current number of movements\" %d\n", d->move_count);
		d->x_pos = x;
		d->y_pos = y;
		if (d->map[y][x] == 'C')
		{
			d->map[y][x] = '0';
			d->colect_num--;
		}
		if (d->map[d->y_pos][d->x_pos] == 'E' && d->colect_num <= 0)
		{
			printf("Escaped\n");
			exit (0);
		}
	}
}

int	ft_key_pressed(int key, t_data *d)
{
	if (key == KEY_W)
		try_move(d, d->x_pos, d->y_pos - 1);
	if (key == KEY_S)
		try_move(d, d->x_pos, d->y_pos + 1);
	if (key == KEY_A)
		try_move(d, d->x_pos - 1, d->y_pos);
	if (key == KEY_D)
		try_move(d, d->x_pos + 1, d->y_pos);
	if (key == KEY_ESC)
	{
		printf("pressed ESC\n");
		exit(0);
	}
	ft_key_reflect(d);
	return (0);
}

int	ft_xxx(t_data *d)
{
	d->tmp42 = 0;
	printf("pressed [x]\n");
	exit(0);
	return (0);
}
