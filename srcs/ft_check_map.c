/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:04:41 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/05 19:59:31 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_wall_row(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_wall_col(t_data *d, int x, int y)
{
	while (d->map[y] && d->map[y][x] && y < d->map_height)
	{
		if (d->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	check_frame(t_data *d)
{
	if (check_wall_row(&(d->map[0])) == 0)
		put_error(d, "invalid map: The map must be closed [up]");
	if (check_wall_row(&(d->map[d->map_height - 1])) == 0)
		put_error(d, "invalid map: The map must be closed [down]");
	if (check_wall_col(d, 0, 0) == 0)
		put_error(d, "invalid map: The map must be closed [left]");
	if (check_wall_col(d, d->map_width - 1, 0) == 0)
		put_error(d, "invalid map: The map must be closed [right]");
}

void	check_valid_map(t_data *d)
{
	if (d->check_escape == 0)
	{
		put_error(d, "invalid map: map exit");
	}
	if (d->check_player != 1)
	{
		put_error(d, "invalid map: player");
	}
	if (d->colect_num == 0)
	{
		put_error(d, "invalid map: collectible");
	}
	check_frame(d);
}
