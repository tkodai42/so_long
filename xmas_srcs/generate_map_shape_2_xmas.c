#include "so_long_xmas.h"

void	shape_set_status_2(t_data *d, int x, int y, t_mass *mass)
{
	if (x == 0)
	{
		mass->left = 1;
		mass->up_left = 1;
		mass->down_left = 1;
	}
	if (x == d->map_width - 1)
	{
		mass->right = 1;
		mass->up_right = 1;
		mass->down_right = 1;
	}
	if (y == 0)
	{
		mass->up = 1;
		mass->up_right = 1;
		mass->up_left = 1;
	}
	if (y == d->map_height - 1)
	{
		mass->down = 1;
		mass->down_left = 1;
		mass->down_right = 1;
	}
}

void	shape_set_status(t_data *d, int x, int y, t_mass *mass)
{
	if (y != 0 && d->map[y - 1][x] == '1')
		mass->up = 1;
	if (y != d->map_height && d->map[y + 1][x] == '1')
		mass->down = 1;
	if (x != 0 && d->map[y][x - 1] == '1')
		mass->left = 1;
	if (x != d->map_width && d->map[y][x + 1] == '1')
		mass->right = 1;
	if (y != 0 && x != 0 && d->map[y - 1][x - 1] == '1')
		mass->up_left = 1;
	if (y != 0 && x != d->map_width && d->map[y - 1][x + 1] == '1')
		mass->up_right = 1;
	if (y != d->map_height && x != 0 && d->map[y + 1][x - 1] == '1')
		mass->down_left = 1;
	if (y != d->map_height && x != d->map_width && d->map[y + 1][x + 1] == '1')
		mass->down_right = 1;
	shape_set_status_2(d, x, y, mass);
}

void	shape_put_cross_2(t_data *d, int tab_x, int tab_y, t_mass mass)
{
	int		x;
	int		y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			if ((3 <= y % 8 && y % 8 < 5) || (3 <= x % 8 && x % 8 < 5))
			{
				if ((3 <= y % 8 && y % 8 < 5) && (3 <= x % 8 && x % 8 < 5))
					d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLUE;
				if ((mass.up && y % 8 <= 2) || (mass.down && 5 <= y % 8) || \
					(mass.left && x % 8 <= 2) || (mass.right && 5 <= x % 8))
					d->dotmap[y + tab_y * 8][x + tab_x * 8] = BLUE;
			}
			x++;
		}
		y++;
	}	
}

void	shape_put_cross(t_data *d, int tab_x, int tab_y)
{
	t_mass	mass;

	shape_init_mass(&mass);
	if (tab_y != 0 && d->map[tab_y - 1][tab_x] == '1')
		mass.up = 1;
	if (tab_y != d->map_height - 1 && d->map[tab_y + 1][tab_x] == '1')
		mass.down = 1;
	if (tab_x != 0 && d->map[tab_y][tab_x - 1] == '1')
		mass.left = 1;
	if (d->map[tab_y][tab_x + 1] == '1')
		mass.right = 1;
	shape_put_cross_2(d, tab_x, tab_y, mass);
}
