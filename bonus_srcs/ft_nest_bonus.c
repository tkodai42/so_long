/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:28:16 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/12 13:49:49 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_nest_pac(t_data *d, t_pac *pac)
{
	if (pac == &(d->pac_1))
		d->nest.p1 = pac;
	if (pac == &(d->pac_2))
		d->nest.p2 = pac;
	if (pac == &(d->pac_3))
		d->nest.p3 = pac;
	if (pac == &(d->pac_4))
		d->nest.p4 = pac;
}

void	nest_move_pac(t_data *d, t_pac *pac)
{
	pac->move_dx = 0;
	pac->move_dy = 0;
	if (pac->nest_status == INTO)
	{
		nest_into(d, pac);
		return ;
	}
	if (pac->nest_status == OUTOF)
	{
		nest_outof(d, pac);
		return ;
	}
	if (pac->nest_status == HOLD)
	{
		nest_hold(d, pac);
	}
}

void	ft_nest(t_data *d, t_pac *pac)
{
	set_nest_pac(d, pac);
	nest_move_pac(d, pac);
}
