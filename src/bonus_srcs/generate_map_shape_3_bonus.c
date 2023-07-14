#include "so_long_bonus.h"

void	shape_diago_up(t_data *d, int tab_x, int tab_y)
{
	int		up_left;
	int		up_right;
	int		x;
	int		y;

	up_left = 0;
	up_right = 0;
	if (tab_y != 0 && tab_x != 0 && d->map[tab_y - 1][tab_x - 1] == '0')
		up_left = 1;
	if (tab_y != 0 && d->map[tab_y - 1][tab_x + 1] == '0')
		up_right = 1;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 8)
		{
			if ((up_left && x < 4) || (up_right && x >= 4))
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}

void	shape_diago_down(t_data *d, int tab_x, int tab_y)
{
	int		down_left;
	int		down_right;
	int		x;
	int		y;

	down_left = 0;
	down_right = 0;
	if (tab_y == d->map_height - 1)
		return ;
	if (tab_x != 0 && d->map[tab_y + 1][tab_x - 1] == '0')
		down_left = 1;
	if (d->map[tab_y + 1][tab_x + 1] == '0')
		down_right = 1;
	y = 4;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if ((down_left && x < 4) || (down_right && x >= 4))
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}

// ================
void	shape_up_down(t_data *d, int tab_x, int tab_y, t_mass *mass)
{
	int		x;
	int		y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if ((mass->up == 0 && y < 4) || (mass->down == 0 && y >= 4))
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}

void	shape_right_left(t_data *d, int tab_x, int tab_y, t_mass *mass)
{
	int		x;
	int		y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if ((mass->left == 0 && x < 4) || (mass->right == 0 && x >= 4))
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}

void	shape_kill_pillar(t_data *d, int tab_x, int tab_y, t_mass *mass)
{
	int		x;
	int		y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if (y < 3 && mass->up_left && mass->up && \
				mass->up_right && mass->right && mass->left)
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			if (y >= 5 && mass->down_left && mass->down && \
				mass->down_right && mass->right && mass->left)
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			if (x < 3 && mass->up_left && mass->left && \
				mass->down_left && mass->up && mass->down)
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			if (x >= 5 && mass->up_right && mass->right && \
				mass->down_right && mass->up && mass->down)
				d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}
