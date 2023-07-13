/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_xmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:29:58 by tkodai            #+#    #+#             */
/*   Updated: 2021/12/23 16:08:18 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_tex_color(t_data *d, int x, int y)
{
	int		color;

	color = *(unsigned int *)(d->xpm_addr + y * d->line_len + x * 4);
	return (color);
}

int	get_tex_color2(t_data *d, int x, int y)
{
	int		color;

	color = *(unsigned int *)(d->xpm_addr2 + y * d->line_len2 + x * 4);
	return (color);
}

int	get_tex_color3(t_data *d, int x, int y, int i)
{
	int		color;

	color = *(unsigned int *)(d->xpm_addr_c[i] + y * d->line_len_c[i] + x * 4);
	return (color);
}

//xmas
int	get_tex_color_xmas(t_data *d, int x, int y)
{
	int		color;

	color = *(unsigned int *)(d->xmas_xpm_addr + y * d->xmas_line_len + x * 4);
	return (color);
}

int	get_tex_color_bomb(t_data *d, int x, int y)
{
	int		color;

	color = *(unsigned int *)(d->bomb_xpm_addr + y * d->bomb_line_len + x * 4);
	return (color);
}
