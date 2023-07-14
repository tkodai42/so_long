#include "so_long_xmas.h"

typedef struct s_edge
{
	int		up;
	int		down;
	int		left;
	int		right;
}				t_edge;

void	init_edge(t_edge *edge)
{
	edge->up = 0;
	edge->down = 0;
	edge->left = 0;
	edge->right = 0;
}

void	set_edge(t_data *d, int *x, int *y, t_xy *xy)
{
	while (1)
	{
		*x += xy->x;
		*y += xy->y;
		if (d->dotmap[*y][*x] == BLUE)
		{
			return ;
		}
	}
}

void	get_nest_edge(t_data *d, t_edge *edge)
{
	int		x;
	int		y;
	t_xy	xy;

	x = d->nest.door1_x * 8;
	edge->up = d->nest.door1_y * 8;
	xy.x = 0;
	xy.y = 1;
	set_edge(d, &x, &(edge->up), &xy);
	edge->down = edge->up;
	xy.x = 0;
	xy.y = 1;
	set_edge(d, &x, &(edge->down), &xy);
	y = edge->up + 10;
	edge->right = d->nest.door1_x * 8;
	xy.x = 1;
	xy.y = 0;
	set_edge(d, &(edge->right), &y, &xy);
	y = edge->up + 10;
	edge->left = d->nest.door1_x * 8;
	xy.x = -1;
	xy.y = 0;
	set_edge(d, &(edge->left), &y, &xy);
}

void	write_nest_edge(t_data *d, t_edge *edge)
{
	int		x;
	int		y;

	y = edge->up;
	while (y <= edge->down)
	{
		x = edge->left;
		while (x <= edge->right)
		{
			if (y == edge->up || y == edge->down || \
				x == edge->left || x == edge->right)
				d->dotmap[y][x] = BLUE;
			else
				d->dotmap[y][x] = BLACK;
			x++;
		}
		y++;
	}
}

void	generate_nest_make_frame(t_data *d)
{
	t_edge	edge;

	init_edge(&edge);
	get_nest_edge(d, &edge);
	write_nest_edge(d, &edge);
	edge.up += 3;
	edge.down += -3;
	edge.left += 3;
	edge.right += -3;
	write_nest_edge(d, &edge);
}
