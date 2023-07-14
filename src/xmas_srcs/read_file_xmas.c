/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:01:50 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/16 16:01:22 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_xmas.h"

// 0 empty space
// 1 wall
// C collectible
// E exit
// P player

// X power cookie
// N nest
// D door
// W Warp

static void	init_read_file(t_data *d)
{
	d->nest.door1_x = 0;
	d->nest.door1_y = 0;
	d->nest.door2_x = 0;
	d->nest.door2_y = 0;
	d->pellet_num = 0;
	d->pellet_num_og = 0;
	d->repaint = 0;
}

static int	get_file_fd(t_data *d)
{
	int		fd;

	if (d->file_name)
		fd = open(d->file_name, O_RDWR);
	else
		//fd = open("./map/bonus_map/map.ber", O_RDWR);
		fd = open("./map/bonus_map/xmas2.ber", O_RDWR);
	if (fd <= 0)
	{
		printf("Error\nInvalid fd\n");
		exit (1);
	}
	return (fd);
}

static void	set_lines(t_data *d, int i, char *line)
{
	d->map[i] = line;
	d->map_pellet[i] = ft_strdup(line);
	d->map_pellet_og[i] = ft_strdup(line);
}

void	read_file_check(t_data *d)
{
	int		flag;
	int		i;

	flag = 0;
	if (d->nest.door1_x == 0)
		flag = 1;
	i = 0;
	while (i < d->map_height)
	{
		if (d->map_width != ft_strlen(d->map[i]))
		{
			flag = 1;
		}
		i++;
	}
	if (flag)
	{
		printf("Error\nInvalid map\n");
		exit (1);
	}
}

void	ft_read_file(t_data *d)
{
	int		ret;
	char	*line;
	int		i;
	int		fd;

	init_read_file(d);
	fd = get_file_fd(d);
	i = 0;
	line = NULL;
	while (1)
	{
		ret = get_next_line(fd, &line);
		set_lines(d, i, line);
		check_line(d, d->map[i], i);
		i++;
		if (ret <= 0)
		{
			d->map[i] = NULL;
			d->map_pellet[i] = NULL;
			d->map_pellet_og[i] = NULL;
			d->map_width = ft_strlen(d->map[0]);
			d->map_height = i - 1;
			return (read_file_check(d));
		}
	}
}
