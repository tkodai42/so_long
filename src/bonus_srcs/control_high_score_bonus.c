/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_high_score.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:04:36 by tkodai            #+#    #+#             */
/*   Updated: 2021/07/29 14:24:25 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_score_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	score_atoi(char *str)
{
	int		ret;
	int		digit;

	ret = 0;
	digit = 0;
	if (str == NULL || *str == 0)
		return (-1);
	while (*str)
	{
		if (is_score_digit(*str) == 0)
			return (-1);
		ret *= 10;
		ret += *str - '0';
		str++;
		digit++;
		if (digit > 8)
			return (-1);
	}
	return (ret);
}

void	score_itoa(int num, char *buf, int *index)
{
	if (num > 9)
	{
		score_itoa(num / 10, buf, index);
	}
	buf[*index] = num % 10 + '0';
	(*index)++;
	buf[*index] = 0;
}

void	read_high_score(t_data *d)
{
	int		fd;
	char	buf[15];
	int		ret;

	fd = open("./.HIGH_SCORE.txt", O_RDWR);
	if (fd <= 0)
	{
		d->high_score = 0;
		return ;
	}
	ret = read(fd, buf, 10);
	buf[ret] = 0;
	d->high_score = score_atoi(buf);
	if (d->high_score == -1)
		d->high_score = 0;
	close(fd);
}

void	write_high_score(t_data *d)
{
	int		fd;
	char	buf[20];
	int		index;

	fd = open("./.HIGH_SCORE.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);
	buf[0] = 0;
	index = 0;
	score_itoa(d->high_score, buf, &index);
	write(fd, buf, index);
	close(fd);
}

/*
int		main()
{
	t_data d;

	read_high_score(&d);
	printf("score %d\n", d.high_score);
	d.high_score = 10;	
	write_high_score(&d);
}
*/
