#include "../so_long_bonus.h"

void	set_xy(t_xy *xy, int x, int y)
{
	xy->x = x;
	xy->y = y;
}

void	generate_nest_make_gate_2(t_data *d)
{
	int		x;
	int		y;

	y = 5;
	while (y < 7)
	{
		x = -1;
		while (x < 17)
		{
			if (x == -1 || x == 16)
				d->dotmap[y + d->nest.door1_y * 8][x + \
					d->nest.door1_x * 8] = BLUE;
			else
				d->dotmap[y + d->nest.door1_y * 8][x + \
					d->nest.door1_x * 8] = PINK;
			x++;
		}
		y++;
	}
}

void	generate_nest_make_gate(t_data *d)
{
	int		x;
	int		y;

	y = 4;
	while (y < 8)
	{
		x = 0;
		while (x < 16)
		{
			d->dotmap[y + d->nest.door1_y * 8][x + d->nest.door1_x * 8] = BLACK;
			x++;
		}
		y++;
	}
	generate_nest_make_gate_2(d);
}

void	generate_nest(t_data *d)
{
	if (!(d->nest.door1_x && d->nest.door1_y))
		return ;
	generate_nest_make_frame(d);
	generate_nest_make_gate(d);
	//xmas
	int		x;
	int		y;

	y = -10;
	while (y < 40)
	{
		x = -20;
		while (x < 40)
		{
			d->dotmap[y + d->nest.door1_y * 8][x + d->nest.door1_x * 8] = BLACK;
			x++;
		}
		y++;
	}
}
