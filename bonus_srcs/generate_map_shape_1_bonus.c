#include "so_long_bonus.h"

void	shape_del_central_4(t_data *d, int tab_x, int tab_y)
{
	int		x;
	int		y;

	y = 2;
	while (y < 6)
	{
		x = 2;
		while (x < 6)
		{
			d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}

void	shape_make_edge1(t_data *d, int tag_x, int tag_y, t_mass *mass)
{
	if (!mass->up_left && !mass->up && !mass->left)
	{
		shape_del_central_4(d, tag_x, tag_y);
		d->dotmap[5 + tag_y * 8][5 + tag_x * 8] = BLUE;
	}
	if (!mass->up_right && !mass->up && !mass->right)
	{
		shape_del_central_4(d, tag_x, tag_y);
		d->dotmap[5 + tag_y * 8][2 + tag_x * 8] = BLUE;
	}
	if (!mass->down_left && !mass->down && !mass->left)
	{
		shape_del_central_4(d, tag_x, tag_y);
		d->dotmap[2 + tag_y * 8][5 + tag_x * 8] = BLUE;
	}
	if (!mass->down_right && !mass->down && !mass->right)
	{
		shape_del_central_4(d, tag_x, tag_y);
		d->dotmap[2 + tag_y * 8][2 + tag_x * 8] = BLUE;
	}
}

void	shape_del_central_2(t_data *d, int tab_x, int tab_y)
{
	int		x;
	int		y;

	y = 3;
	while (y < 5)
	{
		x = 3;
		while (x < 5)
		{
			d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}

void	shape_make_edge2(t_data *d, int tag_x, int tag_y, t_mass *mass)
{
	if (!mass->up_left && mass->up && mass->left)
	{
		shape_del_central_2(d, tag_x, tag_y);
		d->dotmap[3 + tag_y * 8][3 + tag_x * 8] = BLUE;
	}
	if (!mass->up_right && mass->up && mass->right)
	{
		shape_del_central_2(d, tag_x, tag_y);
		d->dotmap[3 + tag_y * 8][4 + tag_x * 8] = BLUE;
	}
	if (!mass->down_left && mass->down && mass->left)
	{
		shape_del_central_2(d, tag_x, tag_y);
		d->dotmap[4 + tag_y * 8][3 + tag_x * 8] = BLUE;
	}
	if (!mass->down_right && mass->down && mass->right)
	{
		shape_del_central_2(d, tag_x, tag_y);
		d->dotmap[4 + tag_y * 8][4 + tag_x * 8] = BLUE;
	}
}

void	shape_kill_fill_mass(t_data *d, int tab_x, int tab_y, t_mass *mass)
{
	int		x;
	int		y;

	if (mass->up && mass->down && mass->left && mass->right)
	{
		if (mass->up_left && mass->up_right && \
			mass->down_left && mass->down_right)
		{
			y = 0;
			while (y < 8)
			{
				x = 0;
				while (x < 8)
				{
					d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLACK;
					x++;
				}
				y++;
			}
		}
	}
}
