/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cb_set_anime_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:46:08 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/15 16:34:36 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_anime_tex_ghost1(t_data *d, t_tex *tex)
{
	int		frame;

	frame = d->cb.frame % 12;
	frame /= 6;
	tex->start_x = 86 + frame * 20;
	tex->start_y = 86;
	if (d->cb.pac3.sprite_count)
	{
		frame = d->cb.frame % 22;
		frame /= 11;
		if (d->cb.pac3.sprite_count < 36)
			tex->start_x = 86 + frame * 20;
		else if (d->cb.pac3.sprite_count < 61)
			tex->start_x = 86;
		else if (d->cb.pac3.sprite_count < 91)
		{
			tex->start_x = 126;
			tex->start_y = 226;
		}
		else
		{
			tex->start_x = 126 + 20;
			tex->start_y = 226;
		}
	}
}

void	set_anime_tex_pacs(t_data *d, t_pac *pac, t_tex *tex)
{
	int		frame;

	frame = d->cb.frame % 4;
	if (pac->type == ANIME_PAC)
	{
		if (frame == 1 || frame == 3)
			frame = 0;
		else if (frame == 0)
			frame = 2;
		else
			frame = 1;
		tex->start_x = 6 + frame * 20;
		tex->start_y = 6;
	}
	if (pac->type == ANIME_PAC_BIG)
	{
		if (frame == 1 || frame == 3)
			frame = 1;
		else if (frame == 0)
			frame = 0;
		else
			frame = 2;
		tex->start_x = 286;
		tex->start_y = 86 - 40 * frame;
	}
}

void	set_anime_tex_ghosts(t_data *d, t_pac *pac, t_tex *tex)
{
	int		frame;

	if (pac->type == ANIME_GHOST2)
	{
		frame = d->cb.frame % 12;
		frame /= 6;
		tex->start_x = 126 + frame * 20;
		tex->start_y = 166;
	}
	if (pac->type == ANIME_GHOST3)
	{
		frame = d->cb.frame % 6;
		frame /= 3;
		tex->start_x = 126 - 2 + frame * -2;
		tex->start_y = 186 + frame * 20;
	}
	if (pac->type == ANIME_GHOST_RUN)
	{
		frame = d->cb.frame % 12;
		frame /= 6;
		tex->start_x = 6 + frame * 20;
		tex->start_y = 166;
	}
}

void	set_anime_tex(t_data *d, t_pac *pac, t_tex *tex)
{
	if (pac->type == ANIME_GHOST1)
		set_anime_tex_ghost1(d, tex);
	else if (pac->type == ANIME_GHOST2 || pac->type == ANIME_GHOST3 || \
		pac->type == ANIME_GHOST_RUN)
		set_anime_tex_ghosts(d, pac, tex);
	else if (pac->type == ANIME_PAC_BIG || pac->type == ANIME_PAC)
		set_anime_tex_pacs(d, pac, tex);
	else if (pac->type == ANIME_PILE)
	{
		tex->start_y = 262;
		if (pac->sprite_count == 0)
			tex->start_x = 26 - 20;
		else if (pac->sprite_count < 8)
			tex->start_x = 26;
		else if (pac->sprite_count < 20)
			tex->start_x = 26 + 20;
		else if (pac->sprite_count < 61)
			tex->start_x = 26 + 40;
		else
			tex->start_x = 26 + 60;
	}
}

void	set_anime_color(t_data *d, t_tex *tex)
{
	tex->color = get_tex_color(d, tex->start_x + tex->x, tex->start_y + tex->y);
}
