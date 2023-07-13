/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:27:52 by tkodai            #+#    #+#             */
/*   Updated: 2022/01/05 15:19:32 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//xmas
void	put_tmp(t_data *d, int x, int y)
{

//	for (int i = 0; i < 1; i++)
	my_mlx_pixel_put(d, x, y, LIME);
	my_mlx_pixel_put_og(d, x, y, RED);
}

int	get_tex_color_bomb(t_data *d, int x, int y);

static int cupple_pos = 0;
static int cupple_var_pos = 0;

void	set_bomb(t_data *d)
{
	cupple_pos++;

	int		start_y = ((double)d->nest.door_c_y + 2.5) * 8;
	int		end_y = (double)(d->nest.door_c_y + 3 + 6) * 8;

	int		start_x = ((double)d->nest.door_c_x - 2.5) * 8;

	int		height = (end_y - start_y) * d->size;
	int		width = d->bomb_xpm_width * ((double)height / d->bomb_xpm_height);

	int color = 0;
	start_x *= d->size;
	start_y *= d->size;
	for (int _y = 0; _y < height; _y++)
	{
		for (int _x = 0; _x < width; _x++)
		{
			color = get_tex_color_bomb(d, d->bomb_xpm_width * ((double)_x / width),
					d->bomb_xpm_height * ((double)_y / height));
			if (color > 0)
			my_mlx_pixel_put_og(d, _x + start_x, _y + start_y, color);
		}
	}
}


int	get_tex_color_xmas(t_data *d, int x, int y);

#define PI 3.14159

void	set_couple(t_data *d)
{
//	int		nest_x = d->nest.door_c_x;
//	int		nest_y = d->nest.door_c_y;

//	int		start_x = (double)(d->nest.door_c_x) * 8;
	int		start_y = ((double)d->nest.door_c_y + 2.5) * 8;
	int		end_y = (double)(d->nest.door_c_y + 3 + 6) * 8;

	int		start_x = ((double)d->nest.door_c_x - 2.5) * 8;
//	int		end_x = (double)(d->nest.door_c_x + 3 + 5) * 8;

	int		height = (end_y - start_y) * d->size;
	int		width = d->xmas_xpm_width * ((double)height / d->xmas_xpm_height);


	int color = 0;
	//move
	double tmp_pos = sin(cupple_pos) * 25;
	cupple_var_pos++;
	double tmp2_pos = sin(cupple_var_pos * PI / 20) * -7;

	start_x *= d->size;
	start_y *= d->size;
	for (int _y = 0; _y < height; _y++)
	{
		for (int _x = 0; _x < width; _x++)
		{
			color = get_tex_color_xmas(d, d->xmas_xpm_width * ((double)_x / width),
					d->xmas_xpm_height * ((double)_y / height));
			if (color > 0)
			my_mlx_pixel_put_og(d, _x + start_x + tmp_pos, _y + start_y + tmp2_pos, color);
		}
	}

	if (d->bomb_flag)
		set_bomb(d);
	else
		cupple_pos = 0;
	d->bomb_flag = 0;
}

#define SNOW_LIMIT	20000

void	ft_snow(t_data *d)
{
	static int first = 0;
	static int x[SNOW_LIMIT];
	static int y[SNOW_LIMIT];
//	static int x_sigh[SNOW_LIMIT];
	static int turn = 0;
	
	turn++;
	if (turn >= 2)
		turn = 0;
	if (first == 0)
	{
		first++;
		for (int i = 0; i < SNOW_LIMIT; i++)
		{
			x[i] = (rand() % d->width / d->size);
			y[i] = (rand() % d->height / d->size);
			d->snow_num = 300;
		}
	}
	for (int i = 0; i < SNOW_LIMIT; i++)
	{
		if (i % 2 == 0)
		//if (i < SNOW_LIMIT / 2)
		{
			if (turn == 0)
			{
				y[i]++;
			/*int tmp = rand() % 3;
			if (tmp == 0)
				x_sigh[i]++;
			else if (tmp == 1)
				x_sigh[i]--;
			if (x_sigh[i] > 0)
				x[i]++;
			else if (x_sigh[i] < 0)
				x[i]--;*/
			}
		}
		else
		{
			y[i]++;
		/*	int tmp = rand() % 3;
			if (tmp == 0)
				x_sigh[i]++;
			else if (tmp == 1)
				x_sigh[i]--;
			if (x_sigh[i] > 0)
				x[i]++;
			else if (x_sigh[i] < 0)
				x[i]--;*/

		}
		//fix
		if (y[i] > d->height / d->size)
			y[i] = 0;
		if (x[i] > d->width / d->size)
			x[i] = 0;
		if (x[i] < 0)
			x[i] = d->width / d->size;
		if (i < d->snow_num)
		my_mlx_pixel_put(d, x[i], y[i], WHITE);
	}
}

//--------

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
	//xmas
	set_couple(d);

	if (d->clear_flag == 1)
	{
		real_clear(d);
		d->clear_flag = 0;
	}
	if (d->cb.coffee == 1)
		ft_coffee_break(d);
	ft_snow(d);
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
//		put_dotghost(d, &d->pac_2, PINK);
//		put_dotghost(d, &d->pac_3, CYAN);
//		put_dotghost(d, &d->pac_4, ORANGE);
		put_dotghost(d, &d->pac_2, RED);
		put_dotghost(d, &d->pac_3, RED);
		put_dotghost(d, &d->pac_4, RED);

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
