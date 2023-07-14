#include "so_long_xmas.h"

void	fix_dotmap_edge(t_data *d)
{
	t_xy	pos;

	pos.x = 0;
	pos.y = 0;
	put_dotmap_edge(d, pos, UP_LEFT);
	pos.x = 0;
	pos.y = d->map_height * 8 - 8;
	d->dotmap[pos.y][pos.x] = RED;
	put_dotmap_edge(d, pos, DOWN_LEFT);
	pos.x = d->map_width * 8 - 8;
	pos.y = 0;
	put_dotmap_edge(d, pos, UP_RIGHT);
	pos.x = d->map_width * 8 - 8;
	pos.y = d->map_height * 8 - 8;
	put_dotmap_edge(d, pos, DOWN_RIGHT);
}

void	fix_pathway(t_data *d, t_outframe *oframe)
{
	fix_path_row(d, 0);
	fix_path_row(d, d->map_width - 1);
	oframe->tmp42 = 0;
}

void	put_out_frame(t_data *d)
{
	t_outframe	oframe;

	set_outframe(d, &oframe);
	put_outframe1(d, &oframe);
	fix_pathway(d, &oframe);
	fix_dotmap_edge(d);
}
