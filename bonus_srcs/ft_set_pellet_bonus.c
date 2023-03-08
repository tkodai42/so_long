/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pellet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:10:52 by tkodai            #+#    #+#             */
/*   Updated: 2021/07/23 21:28:33 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_set_pellet(t_data *d)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (d->map_pellet_og[y])
	{
		x = 0;
		while (d->map_pellet_og[y][x])
		{
			d->map_pellet[y][x] = d->map_pellet_og[y][x];
			x++;
		}
		y++;
	}
}
