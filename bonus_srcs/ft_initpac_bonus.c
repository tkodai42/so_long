/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initpac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:39:46 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/14 14:03:59 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_init_pac_type4(t_data *d, t_pac *pac)
{
	pac->dx = (d->nest.door_c_x + 2) * 1000;
	pac->dy = (d->nest.door_c_y + 3) * 1000;
	pac->nest_dx = pac->dx;
	pac->nest_dy = pac->dy;
	pac->x = pac->dx / 1000;
	pac->y = pac->dy / 1000;
	pac->home_pos_dx = 1000;
	pac->home_pos_dy = d->map_height * 1000;
}

static void	ft_init_pac_type3(t_data *d, t_pac *pac)
{
	pac->dx = (d->nest.door_c_x - 2) * 1000;
	pac->dy = (d->nest.door_c_y + 3) * 1000;
	pac->nest_dx = pac->dx;
	pac->nest_dy = pac->dy;
	pac->x = pac->dx / 1000;
	pac->y = pac->dy / 1000;
	pac->home_pos_dx = d->map_width * 1000;
	pac->home_pos_dy = d->map_height * 1000;
}

static void	ft_init_pac_type2(t_data *d, t_pac *pac)
{
	pac->dx = (d->nest.door_c_x) * 1000;
	pac->dy = (d->nest.door_c_y + 3) * 1000;
	pac->nest_dx = pac->dx;
	pac->nest_dy = pac->dy;
	pac->x = pac->dx / 1000;
	pac->y = pac->dy / 1000;
	pac->home_pos_dx = 1000;
	pac->home_pos_dy = 1000;
}

static void	ft_init_pac_type1(t_data *d, t_pac *pac)
{
	pac->x = d->nest.door1_x;
	pac->y = d->nest.door1_y - 1;
	pac->dx = pac->x * 1000 + 1000 - 250;
	pac->dy = pac->y * 1000;
	pac->nest_dx = pac->dx;
	pac->nest_dy = pac->dy;
	pac->status = CHASE;
	pac->home_pos_dx = d->map_width * 1000;
	pac->home_pos_dy = 0;
}

void	ft_init_pac(t_data *d, t_pac *pac, int x, int y)
{
	pac->x = x;
	pac->y = y;
	pac->dx = x * 1000;
	pac->dy = y * 1000;
	pac->move_dx = 0;
	pac->move_dy = 0;
	pac->tag_x = 0;
	pac->tag_y = 0;
	pac->status = NEST;
	pac->sprite_count = 0;
	pac->nest_status = HOLD;
	pac->blue_time = 0;
	pac->vanish_count = 0;
	if (pac == &(d->pac_1))
		ft_init_pac_type1(d, pac);
	if (pac == &(d->pac_2))
		ft_init_pac_type2(d, pac);
	if (pac == &(d->pac_3))
		ft_init_pac_type3(d, pac);
	if (pac == &(d->pac_4))
		ft_init_pac_type4(d, pac);
}
