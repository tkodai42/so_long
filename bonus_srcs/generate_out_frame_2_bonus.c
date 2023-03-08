#include "../so_long_bonus.h"

const char	g_ede_tex[8][8] = {{"00001111"},
							{"00110000"},
							{"01000000"},
							{"01000111"},
							{"10001000"},
							{"10010000"},
							{"10010000"},
							{"10010000"}};

// ===== edge =====
int	put_dotmap_edge2(t_data *d, int x, int y, int sign)
{
	int		color;

	color = 0;
	if (sign == UP_LEFT)
	{
		color = g_ede_tex[y][x];
	}
	if (sign == UP_RIGHT)
	{
		color = g_ede_tex[y][7 - x];
	}
	if (sign == DOWN_LEFT)
	{
		color = g_ede_tex[7 - y][x];
	}
	if (sign == DOWN_RIGHT)
	{
		color = g_ede_tex[7 - y][7 - x];
	}
	if (color == '1')
		color = BLUE;
	else
		color = BLACK;
	return (color);
	d->tmp42 = 0;
}

void	put_dotmap_edge(t_data *d, t_xy pos, int sign)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			color = put_dotmap_edge2(d, x, y, sign);
			d->dotmap[pos.y + y][pos.x + x] = color;
			x++;
		}
		y++;
	}
	d->tmp42 = 0;
}

void	set_outframe(t_data *d, t_outframe *oframe)
{
	int		x;
	int		y;
	t_xy	xy;

	x = 1 * 8;
	oframe->up = 0;
	set_xy(&xy, 0, 1);
	set_edge(d, &x, &oframe->up, &xy);
	oframe->left = 0;
	y = 1 * 8;
	set_xy(&xy, 1, 0);
	set_edge(d, &oframe->left, &y, &xy);
	x = (d->map_width - 1) * 8;
	oframe->down = (d->map_height) * 8;
	set_xy(&xy, 0, -1);
	set_edge(d, &x, &oframe->down, &xy);
	oframe->right = (d->map_width) * 8;
	y = (d->map_height - 1) * 8;
	set_xy(&xy, -1, 0);
	set_edge(d, &oframe->right, &y, &xy);
	oframe->up += -3;
	oframe->down += 3;
	oframe->left += -3;
	oframe->right += 3;
}

void	put_outframe1(t_data *d, t_outframe *oframe)
{
	int		x;
	int		y;
	int		ex;
	int		ey;

	x = oframe->left;
	y = oframe->up;
	ex = oframe->right;
	ey = oframe->down;
	while (y <= ey)
	{
		x = oframe->left;
		while (x <= ex)
		{
			if (x == oframe->left || y == oframe->up || x == ex || y == ey)
				d->dotmap[y][x] = BLUE;
			x++;
		}
		y++;
	}
}
