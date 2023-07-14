#include "so_long_bonus.h"

void	shape_init_mass(t_mass *mass)
{
	mass->up = 0;
	mass->down = 0;
	mass->left = 0;
	mass->right = 0;
	mass->up_left = 0;
	mass->up_right = 0;
	mass->down_left = 0;
	mass->down_right = 0;
}

void	shape_mass(t_data *d, int x, int y)
{
	t_mass	mass;

	if (d->map[y][x] == '0')
		return ;
	shape_init_mass(&mass);
	shape_set_status(d, x, y, &mass);
	shape_put_cross(d, x, y);
	shape_diago_up(d, x, y);
	shape_diago_down(d, x, y);
	shape_up_down(d, x, y, &mass);
	shape_right_left(d, x, y, &mass);
	shape_kill_pillar(d, x, y, &mass);
	shape_kill_fill_mass(d, x, y, &mass);
	shape_make_edge1(d, x, y, &mass);
	shape_make_edge2(d, x, y, &mass);
}

void	shape_map(t_data *d)
{
	int		x;
	int		y;

	y = 0;
	while (y < d->map_height)
	{
		x = 0;
		while (x < d->map_width)
		{
			shape_mass(d, x, y);
			x++;
		}
		y++;
	}
	generate_nest(d);
}

static void	xylitol_lime_mint(void)
{
	printf("Error\nmalloc failed\n");
	exit(1);
}

void	ft_generate_dotmap(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	d->dotmap = malloc(sizeof(int *) * (d->map_height * 8 + 10));
	if (d->dotmap == NULL)
		xylitol_lime_mint();
	while (i < d->map_height * 8)
	{
		d->dotmap[i] = malloc(sizeof(int) * (d->map_width * 8 + 10));
		if (d->dotmap[i] == NULL)
			xylitol_lime_mint();
		j = 0;
		while (j < d->map_width * 8)
		{
			d->dotmap[i][j] = BLACK;
			j++;
		}
		d->dotmap[i][j] = 0;
		i++;
	}
	shape_map(d);
	put_out_frame(d);
	repaint_map(d);
}
