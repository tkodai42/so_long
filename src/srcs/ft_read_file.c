/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:04:41 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/05 13:13:22 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_line2(t_data *d, char *line, int i)
{
	int		i2;

	i2 = 0;
	while (line && line[i2])
	{
		if (line[i2] == 'C')
			d->colect_num++;
		else if (line[i2] == 'P')
		{
			d->x_pos = i2;
			d->y_pos = i;
			line[i2] = '0';
			d->check_player++;
		}
		else if (line[i2] == 'E')
			d->check_escape++;
		else if (line[i2] != '0' && line[i2] != '1')
			put_error(d, "invalid map: invalid cell");
		i2++;
	}
}

void	parse_line(t_data *d, char *line, int i)
{
	if (i == 0)
	{
		if (line == NULL)
			put_error(d, "invalid map: NULL");
		d->map_width = ft_strlen(line);
	}
	if (line == NULL)
		return ;
	parse_line2(d, line, i);
}

void	check_file_name(t_data *d)
{
	int			i;
	int			j;
	char		*str;
	const char	check_str[5] = ".ber";

	str = d->file_name;
	i = 0;
	while (str[i])
	{
		i++;
	}
	i += -4;
	if (i <= 0)
		put_error(d, "invalid arg: filename");
	j = 0;
	while (j <= 3)
	{
		if (check_str[j] != str[i])
			put_error(d, "invalid arg: filename");
		j++;
		i++;
	}
}

void	ft_read_file(t_data *d)
{
	int		ret;
	int		i;
	char	*line;
	int		fd;

	i = 0;
	check_file_name(d);
	fd = open(d->file_name, O_RDWR);
	if (fd <= 0)
		put_error(d, "invalid map: fd");
	while (1)
	{
		ret = get_next_line(fd, &line);
		parse_line(d, line, i);
		d->map[i++] = line;
		if (ret == 0)
		{
			d->map_height = i - 1;
			d->map[i] = NULL;
			check_valid_map(d);
			return ;
		}
		if (d->map_width != ft_strlen(line))
			put_error(d, "invalid map: not rectangle");
	}
}
