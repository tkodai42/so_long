#include "../so_long_bonus.h"

const char	g_ghost[16][16] = {{"0000000000000000"},
							{"0000001111000000"},
							{"0000111111110000"},
							{"0001111111111000"},
							{"0011111111111100"},
							{"0011111111111100"},
							{"0011111111111100"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111101111011110"},
							{"0011000110001100"},
							{"0000000000000000"}};

const char	g_ghost2[16][16] = {{"0000000000000000"},
							{"0000001111000000"},
							{"0000111111110000"},
							{"0001111111111000"},
							{"0011111111111100"},
							{"0011111111111100"},
							{"0011111111111100"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0111111111111110"},
							{"0110111001110110"},
							{"0100011001100010"},
							{"0000000000000000"}};

const char	g_pacman1[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000011111000000"},
							{"0001111111110000"},
							{"0011111111111000"},
							{"0011111111111000"},
							{"0111111111111100"},
							{"0111111111111100"},
							{"0111111111111100"},
							{"0111111111111100"},
							{"0111111111111100"},
							{"0011111111111000"},
							{"0011111111111000"},
							{"0001111111110000"},
							{"0000011111000000"},
							{"0000000000000000"}};

const char	g_pacman2[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000011111000000"},
							{"0001111111110000"},
							{"0011111111111000"},
							{"0011111111111000"},
							{"0000111111111100"},
							{"0000000111111100"},
							{"0000000000111100"},
							{"0000000111111100"},
							{"0000111111111100"},
							{"0011111111111000"},
							{"0011111111111000"},
							{"0001111111110000"},
							{"0000011111000000"},
							{"0000000000000000"}};

const char	g_pacman3[16][16] = {{"0000000000000000"},
							{"0000000000000000"},
							{"0000011111000000"},
							{"0000011111110000"},
							{"0000001111111000"},
							{"0000000111111000"},
							{"0000000011111100"},
							{"0000000001111100"},
							{"0000000000111100"},
							{"0000000001111100"},
							{"0000000011111100"},
							{"0000000111111000"},
							{"0000001111111000"},
							{"0000011111110000"},
							{"0000011111000000"},
							{"0000000000000000"}};

const char	g_tank11[16][16] = {{"0000000120000000"},
							{"0000000120000000"},
							{"0233003123002330"},
							{"0121122123333220"},
							{"0332112122333330"},
							{"0122112222333220"},
							{"0332122333233330"},
							{"0122121223233220"},
							{"0332121223233330"},
							{"0122121223233220"},
							{"0332121112233330"},
							{"0122122222233220"},
							{"0331112222333330"},
							{"0122000000001220"},
							{"0000000000000000"},
							{"0000000000000000"}};

int	ret_dotpac_color(t_data *d, int x, int y, const char tex_ary[16][16])
{
	int		color;

	color = 0;
	if (d->executed == KEY_LEFT)
	{
		if (tex_ary[y][x] == '1')
			color = YELLOW;
	}
	if (d->executed == KEY_RIGHT)
	{
		if (tex_ary[y][15 - x] == '1')
			color = YELLOW;
	}
	if (d->executed == KEY_UP)
	{
		if (tex_ary[x][y] == '1')
			color = YELLOW;
	}
	if (d->executed == KEY_DOWN)
	{
		if (tex_ary[x][15 - y] == '1')
			color = YELLOW;
	}
	return (color);
}

void	put_dotpac2(t_data *d, t_pac *pac)
{
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < 16)
		{
			color = 0;
			if (pac->sprite_count == 0)
				color = ret_dotpac_color(d, x, y, g_pacman1);
			else if (pac->sprite_count == 1 || pac->sprite_count == 3)
				color = ret_dotpac_color(d, x, y, g_pacman2);
			else if (pac->sprite_count == 2)
				color = ret_dotpac_color(d, x, y, g_pacman3);
			if (color != 0)
				my_mlx_pixel_put(d, x - 4 + (double)pac->dx / 1000 * 8, \
					y - 4 + (double)pac->dy / 1000 * 8, color);
			x++;
		}
		y++;
	}
}

void	put_dotpac(t_data *d)
{
	t_pac	*pac;

	pac = &d->pac_mine;
	if (pac->sprite_count >= 4)
		pac->sprite_count = 0;
	if (d->game_set == 1)
	{
		d->game_set_count++;
		if (d->game_set_count / 3 <= 14 + 7 && d->pellet_num == 0)
			;
		else if (d->game_set_count / 3 >= 5)
		{
			pacman_dying(d);
			return ;
		}
	}
	put_dotpac2(d, pac);
}

int	ret_body_color_type1(t_data *d, t_pac *pac, int x, int y)
{
	int		color;

	color = 0;
	if (g_ghost2[y][x] == '0')
		color = 0;
	if (g_ghost2[y][x] == '1')
	{
		if (pac->blue_time)
		{
			if (pac->blue_time < 50 && pac->blue_time % 10 < 5 \
					&& d->eat_stop_count == 0)
				color = WHITE;
			else
				color = DARK_BLUE;
		}
		else
			color = pac->color;
	}
	return (color);
}

int	ret_body_color_type2(t_data *d, t_pac *pac, int x, int y)
{
	int		color;

	color = 0;
	if (g_ghost[y][x] == '0')
		color = 0;
	if (g_ghost[y][x] == '1')
	{
		if (pac->blue_time)
		{
			if (pac->blue_time < 50 && pac->blue_time % 10 \
				< 5 && d->eat_stop_count == 0)
				color = WHITE;
			else
				color = DARK_BLUE;
		}
		else
			color = pac->color;
	}
	return (color);
}
