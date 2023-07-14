#include "so_long_xmas.h"

void	write_frame3(t_data *d, t_outframe sframe)
{
	int		x;
	int		y;

	y = sframe.up;
	while (y <= sframe.down)
	{
		x = sframe.left;
		while (x <= sframe.right)
		{
			d->dotmap[y][x] = BLACK;
			x++;
		}
		y++;
	}
}

void	write_frame2(t_data *d, t_outframe sframe)
{
	if (sframe.left < 10)
	{
		sframe.left = 0;
		sframe.right = 8;
	}
	else
	{
		sframe.left = d->map_width * 8 - 8;
		sframe.right = d->map_width * 8;
	}
	sframe.up++;
	sframe.down--;
	write_frame3(d, sframe);
}

void	write_frame(t_data *d, t_outframe sframe)
{
	int		x;
	int		y;

	y = sframe.up;
	while (y <= sframe.down)
	{
		x = sframe.left;
		while (x <= sframe.right)
		{
			if (y == sframe.up || y == sframe.down || \
				x == sframe.right || x == sframe.left)
			{
				if ((sframe.up < y && y < sframe.down) || \
					(sframe.left < x && x < sframe.right))
					d->dotmap[y][x] = BLUE;
			}
			x++;
		}
		y++;
	}
	write_frame2(d, sframe);
}

void	gen_pathway_space_2(t_data *d, t_outframe *sframe, int *expanded_flag)
{
	*expanded_flag = 0;
	if (d->dotmap[sframe->up - 3][(sframe->left + sframe->right) / 2] != BLUE)
	{
		*expanded_flag = 1;
		sframe->up--;
	}
	if (d->dotmap[sframe->down + 3][(sframe->left + sframe->right) / 2] != BLUE)
	{
		*expanded_flag = 1;
		sframe->down++;
	}
	if (d->dotmap[(sframe->up + sframe->down) / 2][sframe->left - 3] != BLUE)
	{
		*expanded_flag = 1;
		sframe->left--;
	}
	if (d->dotmap[(sframe->up + sframe->down) / 2][sframe->right + 3] != BLUE)
	{
		*expanded_flag = 1;
		sframe->right++;
	}
}

void	gen_pathway_space(t_data *d, int x, int y)
{
	t_outframe	sframe;
	int			expanded_flag;

	sframe.up = y * 8;
	sframe.down = y * 8;
	sframe.left = x * 8;
	sframe.right = x * 8;
	expanded_flag = 1;
	while (expanded_flag)
		gen_pathway_space_2(d, &sframe, &expanded_flag);
	write_frame(d, sframe);
}
