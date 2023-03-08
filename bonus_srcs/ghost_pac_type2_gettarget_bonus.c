/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_pac_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:16:29 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/12 19:42:19 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	pac_run(t_data *d, t_pac *pac)
{
	pac->tag_x = pac->x;
	pac->tag_y = pac->y;
	if (d->pac_mine.x < pac->x)
		pac->tag_x += abs(d->pac_mine.x - pac->x) * 2;
	else
		pac->tag_x -= abs(d->pac_mine.x - pac->x) * 2;
	if (d->pac_mine.y < pac->y)
		pac->tag_y += abs(d->pac_mine.y - pac->y) * 2;
	else
		pac->tag_y -= abs(d->pac_mine.y - pac->y) * 2;
	if (pac->tag_y <= 0)
		pac->tag_y = 1;
	if (pac->tag_x <= 0)
		pac->tag_x = 1;
	if (d->map_height - 1 < pac->tag_y)
		pac->tag_y = d->map_height - 2;
	if (d->map_width - 1 < pac->tag_x)
		pac->tag_x = d->map_width - 2;
}

void	get_tag_pac3(t_data *d, t_pac *pac)
{
	if (d->pac_mine.x < d->pac_1.x)
		pac->tag_x -= abs(d->pac_mine.x - d->pac_1.x) * 2 + 1;
	else
		pac->tag_x += abs(d->pac_mine.x - d->pac_1.x) * 2 + 1;
	if (d->pac_mine.y < d->pac_1.y)
		pac->tag_y -= abs(d->pac_mine.y - d->pac_1.y) * 2 + 1;
	else
		pac->tag_y += abs(d->pac_mine.y - d->pac_1.y) * 2 + 1;
	if (pac->tag_y <= 0)
		pac->tag_y = 1;
	if (pac->tag_x <= 0)
		pac->tag_x = 1;
	if (d->map_height - 1 < pac->tag_y)
		pac->tag_y = d->map_height - 2;
	if (d->map_width - 1 < pac->tag_x)
		pac->tag_x = d->map_width - 2;
}

void	get_tag_pac2(t_data *d, t_pac *pac)
{
	pac->tag_x = d->pac_mine.x;
	pac->tag_y = d->pac_mine.y;
	if (d->executed == KEY_UP)
		pac->tag_y -= 5;
	if (d->executed == KEY_DOWN)
		pac->tag_y += 5;
	if (d->executed == KEY_RIGHT)
		pac->tag_x += 5;
	if (d->executed == KEY_LEFT)
		pac->tag_x -= 5;
}

void	get_tag_pac4(t_data *d, t_pac *pac)
{
	if (abs(pac->dx - d->pac_mine.dx) + abs(pac->dy - d->pac_mine.dy) >= 8000)
		return ;
	else if (pac->status == CHASE || pac->status == RUN)
	{
		pac->tag_x = pac->x;
		pac->tag_y = pac->y;
		if (d->pac_mine.x < d->pac_3.x)
			pac->tag_x += abs(d->pac_mine.x - d->pac_3.x) * 2;
		else
			pac->tag_x -= abs(d->pac_mine.x - d->pac_3.x) * 2;
		if (d->pac_mine.y < d->pac_3.y)
			pac->tag_y += abs(d->pac_mine.y - d->pac_3.y) * 2;
		else
			pac->tag_y -= abs(d->pac_mine.y - d->pac_3.y) * 2;
		if (pac->tag_y <= 0)
			pac->tag_y = 1;
		if (pac->tag_x <= 0)
			pac->tag_x = 1;
		if (d->map_height - 1 < pac->tag_y)
			pac->tag_y = d->map_height - 2;
		if (d->map_width - 1 < pac->tag_x)
			pac->tag_x = d->map_width - 2;
	}
}

// === patrol count ===
// patorl 210
// chase  530? + 210
void	get_target(t_data *d, t_pac *pac)
{
	pac->tag_x = d->pac_mine.x;
	pac->tag_y = d->pac_mine.y;
	if (d->all_frame % 630 < 210 && (pac->status == CHASE))
	{
		get_target_patrol(d, pac);
		return ;
	}
	if (pac->status == RUN)
	{
		pac_run(d, pac);
		return ;
	}
	if (pac == &(d->pac_3))
		get_tag_pac3(d, pac);
	if (pac == &(d->pac_2))
		get_tag_pac2(d, pac);
	if (pac == &(d->pac_4))
		get_tag_pac4(d, pac);
	if (pac->tag_y == pac->y && pac->tag_x == pac->x)
	{
		pac->tag_x = d->pac_mine.x;
		pac->tag_y = d->pac_mine.y;
	}
}
