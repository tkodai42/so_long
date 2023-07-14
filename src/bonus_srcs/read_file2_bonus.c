/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:01:50 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/16 14:56:42 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// 0 empty space
// 1 wall
// C collectible
// E exit
// P player

// X power cookie
// N nest
// D door
// W Warp

void	check_line3(t_data *d, char *line, int index, int i)
{
	if (line[i] == 'D' || line[i] == 'N')
	{
		if (line[i] == 'D')
		{
			if (d->nest.door1_x == 0)
			{
				d->nest.door1_x = i;
				d->nest.door1_y = index;
				d->nest.door_c_x = 0.5 + d->nest.door1_x;
				d->nest.door_c_y = d->nest.door1_y - 1;
			}
			else if (d->nest.door2_x == 0)
			{
				d->nest.door2_x = i;
				d->nest.door2_y = index;
			}
		}
		line[i] = '1';
	}
}

void	check_line2(t_data *d, char *line, int index, int i)
{
	if (line[i] == 'X' || line[i] == 'C' || line[i] == 'z')
	{
		if (line[i] == 'z')
		{
			d->map_pellet[index][i] = 'C';
		}
		line[i] = '0';
		d->pellet_num++;
		d->pellet_num_og++;
	}
	if (line[i] == 'S' || line[i] == 'Z')
	{
		line[i] = '0';
	}
	if (line[i] == 'W')
	{
		line[i] = '1';
		d->repaint = 1;
	}
}

void	is_valid_cell(char c, char *str)
{
	while (str && *str)
	{
		if (*str == c)
			return ;
		str++;
	}
	printf("Error\nInvalid map\n");
	exit (1);
}

void	check_line(t_data *d, char *line, int index)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'P')
		{
			is_valid_cell(line[i], "PXCzSZWDN01");
			line[i] = '0';
			d->map_pellet[index][i] = '1';
			d->map_pellet_og[index][i] = '1';
			d->pac_mine.x = i;
			d->pac_mine.y = index;
			d->pac_mine.dx = i * 1000 + 500;
			d->pac_mine.dy = index * 1000;
			d->pac_mine.init_x = d->pac_mine.x;
			d->pac_mine.init_y = d->pac_mine.y;
			d->pac_mine.init_dx = d->pac_mine.dx;
			d->pac_mine.init_dy = d->pac_mine.dy;
		}
		check_line2(d, line, index, i);
		check_line3(d, line, index, i);
		i++;
	}
}
