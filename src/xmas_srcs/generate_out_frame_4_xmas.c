#include "so_long_xmas.h"

void	put_fixed_path(t_data *d, int x, int y)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	while (tmp_y < 24)
	{
		tmp_x = 0;
		while (tmp_x < 8)
		{
			if (tmp_y == 0 || tmp_y == 3 || tmp_y == 20 || tmp_y == 23)
				d->dotmap[tmp_y + y * 8][tmp_x + x * 8] = BLUE;
			else
				d->dotmap[tmp_y + y * 8][tmp_x + x * 8] = BLACK;
			tmp_x++;
		}
		tmp_y++;
	}
}

t_xy	gen_pathway_check1(t_data *d, int x, int y, int move_y)
{
	t_xy	ret;

	ret.x = x;
	ret.y = y;
	while (1)
	{
		if (d->map[ret.y][ret.x] != '1')
			return (ret);
		ret.y += move_y;
	}
	return (ret);
}

void	gen_pathway_edge_up(t_data *d, int x, int y, int sign)
{
	t_xy	xy;

	if (sign == DOWN_LEFT)
	{
		xy = gen_pathway_check1(d, x + 1, y - 1, -1);
		xy.x += -1;
		xy.y += 1;
		xy.x *= 8;
		xy.y *= 8;
		put_dotmap_edge(d, xy, DOWN_LEFT);
	}
	if (sign == DOWN_RIGHT)
	{
		xy = gen_pathway_check1(d, x - 1, y - 1, -1);
		xy.x += 1;
		xy.y += 1;
		xy.x *= 8;
		xy.y *= 8;
		put_dotmap_edge(d, xy, DOWN_RIGHT);
	}
}

void	gen_pathway_edge_down(t_data *d, int x, int y, int sign)
{
	t_xy	xy;

	if (sign == UP_LEFT)
	{
		xy = gen_pathway_check1(d, x + 1, y + 1, 1);
		xy.x += -1;
		xy.y += -1;
		xy.x *= 8;
		xy.y *= 8;
		put_dotmap_edge(d, xy, UP_LEFT);
	}
	if (sign == UP_RIGHT)
	{
		xy = gen_pathway_check1(d, x - 1, y + 1, 1);
		xy.x += 1;
		xy.y += -1;
		xy.x *= 8;
		xy.y *= 8;
		put_dotmap_edge(d, xy, UP_RIGHT);
	}
}

void	fix_path_row(t_data *d, int x)
{
	int		y;

	y = 0;
	while (y < d->map_height)
	{
		if (d->map_pellet_og[y][x] == 'S')
		{
			if (x == 0)
			{
				gen_pathway_space(d, x + 1, y + 2);
				gen_pathway_space(d, x + 2, y - 2);
				gen_pathway_edge_up(d, x, y, DOWN_LEFT);
				gen_pathway_edge_down(d, x, y, UP_LEFT);
			}
			else
			{
				gen_pathway_space(d, x, y + 2);
				gen_pathway_space(d, x - 2, y - 2);
				gen_pathway_edge_up(d, x, y, DOWN_RIGHT);
				gen_pathway_edge_down(d, x, y, UP_RIGHT);
			}
			put_fixed_path(d, x, y - 1);
		}
		y++;
	}
}
