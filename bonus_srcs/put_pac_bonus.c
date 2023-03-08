#include "../so_long_bonus.h"

int	ret_body_color(t_data *d, t_pac *pac, int x, int y)
{
	if (d->frame >= 4)
		return (ret_body_color_type1(d, pac, x, y));
	else
		return (ret_body_color_type2(d, pac, x, y));
	return (0);
}

static void	put_dotghost3(t_data *d, t_pac *pac, int x, int y)
{
	int		color;
	int		tmp_color;

	color = 0;
	if (pac->status != GO_BACK && (!(pac->status == NEST \
		&& pac->nest_status == INTO)))
		color = ret_body_color(d, pac, x, y);
	tmp_color = 0;
	if (d->madness)
		tmp_color = get_madness_eye(d, pac, x, y);
	else
		tmp_color = ret_eye_color(d, pac, x, y);
	if (tmp_color)
		color = tmp_color;
	if (color != 0)
		my_mlx_pixel_put(d, x - 4 + (double)pac->dx / \
			1000 * 8, y - 4 + (double)pac->dy / 1000 * 8, color);
}

void	put_dotghost2(t_data *d, t_pac *pac)
{
	int		x;
	int		y;

	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < 16)
		{
			put_dotghost3(d, pac, x, y);
			x++;
		}
		y++;
	}
}

void	put_dotghost(t_data *d, t_pac *pac, int pac_color)
{
	pac_color = 0;
	if (pac->vanish_count)
		return ;
	put_dotghost2(d, pac);
}
