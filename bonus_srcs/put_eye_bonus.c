#include "../so_long_bonus.h"

const char	g_eye_up[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000220000220000"},
							{"0003223003223000"},
							{"0003333003333000"},
							{"0003333003333000"},
							{"0000330000330000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"}};

const char	g_eye_down[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000330000330000"},
							{"0003333003333000"},
							{"0003333003333000"},
							{"0003223003223000"},
							{"0000220000220000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"}};

const char	g_eye_left[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0003300003300000"},
							{"0033330033330000"},
							{"0022330022330000"},
							{"0022330022330000"},
							{"0003300003300000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"}};

const char	g_eye_blue[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000011001100000"},
							{"0000011001100000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0001100110011000"},
							{"0010011001100100"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"},
							{"0000000000000000"}};

static int	ret_normal_eye2(t_pac *pac, int x, int y)
{
	int		color;

	color = 0;
	if (pac->move_dx > 0)
	{
		if (g_eye_left[y][15 - x] == '2')
			color = BLUE;
		if (g_eye_left[y][15 - x] == '3')
			color = WHITE;
	}
	else
	{
		if (g_eye_left[y][x] == '2')
			color = BLUE;
		if (g_eye_left[y][x] == '3')
			color = WHITE;
	}	
	return (color);
}

int	ret_normal_eye(t_pac *pac, int x, int y)
{
	int		color;

	color = 0;
	if (pac->move_dy < 0)
	{
		if (g_eye_up[y][x] == '2')
			color = BLUE;
		if (g_eye_up[y][x] == '3')
			color = WHITE;
	}
	else if (pac->move_dy > 0)
	{
		if (g_eye_down[y][x] == '2')
			color = BLUE;
		if (g_eye_down[y][x] == '3')
			color = WHITE;
	}
	else
		color = ret_normal_eye2(pac, x, y);
	return (color);
}

int	ret_eye_color(t_data *d, t_pac *pac, int x, int y)
{
	int		color;

	color = 0;
	if (pac->blue_time)
	{
		if (g_eye_blue[y][x] == '1')
		{
			if (pac->blue_time < 50 && pac->blue_time % 10 < 5 \
				&& d->eat_stop_count == 0)
				color = RED;
			else
				color = TUMBLEWEED;
		}	
	}
	else
		color = ret_normal_eye(pac, x, y);
	return (color);
}

static int	get_madness_eye_2(t_data *d, int x, int y)
{
	int		color;
	int		tmp;

	color = 0;
	tmp = d->all_frame % 8 / 2;
	if (tmp == 1)
	{
		if (g_eye_left[y][15 - x] == '2')
			color = RED;
		if (g_eye_left[y][15 - x] == '3')
			color = BLACK + 1;
	}
	else
	{
		if (g_eye_left[y][x] == '2')
			color = RED;
		if (g_eye_left[y][x] == '3')
			color = BLACK + 1;
	}
	return (color);
}

int	get_madness_eye(t_data *d, t_pac *pac, int x, int y)
{
	int		tmp;
	int		color;

	color = 0;
	pac->tmp42 = 0;
	tmp = d->all_frame % 8 / 2;
	if (tmp == 0)
	{
		if (g_eye_up[y][x] == '2')
			color = RED;
		if (g_eye_up[y][x] == '3')
			color = BLACK + 1;
	}
	else if (tmp == 2)
	{
		if (g_eye_down[y][x] == '2')
			color = RED;
		if (g_eye_down[y][x] == '3')
			color = BLACK + 1;
	}
	else
		color = get_madness_eye_2(d, x, y);
	return (color);
}
