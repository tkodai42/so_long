/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:27:52 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/13 14:41:56 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_solong_act2(t_data *d)
{
	if (d->all_frame == 1)
		put_start_logo(d);
	if (d->game_set == 1 && d->life_stock == 0 && \
		d->game_set_count / 3 > 18 && d->pellet_num)
		put_end_logo(d);
	put_score(d);
	if (d->show_root)
	{
		show_target(d, &d->pac_1, RED);
		show_target(d, &d->pac_2, PINK);
		show_target(d, &d->pac_3, CYAN);
		show_target(d, &d->pac_4, ORANGE);
	}
	if (d->clear_flag == 1)
	{
		real_clear(d);
		d->clear_flag = 0;
	}
	if (d->cb.coffee == 1)
		ft_coffee_break(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}

void	ft_solong_act(t_data *d)
{
	mlx_do_sync(d->mlx_ptr);
	ft_put_dotmap(d);
	ft_fruits(d);
	if (d->game_set == 0)
		move_ghosts(d);
	put_dot(d);
	if (d->eat_stop_count == 0)
		put_dotpac(d);
	else
		put_kill_ghost_score(d);
	if (d->game_set_count / 3 < 5)
	{
		put_dotghost(d, &d->pac_1, RED);
		put_dotghost(d, &d->pac_2, PINK);
		put_dotghost(d, &d->pac_3, CYAN);
		put_dotghost(d, &d->pac_4, ORANGE);
	}
	fixed_blue(d);
	eat_stop_count(d);
	move_jump_pac(d, &d->pac_mine);
	move_jump_pac(d, &d->pac_1);
	move_jump_pac(d, &d->pac_2);
	move_jump_pac(d, &d->pac_3);
	move_jump_pac(d, &d->pac_4);
	ft_solong_act2(d);
}
