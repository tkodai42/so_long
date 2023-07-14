#include "so_long_bonus.h"

int	ret_color(t_data *d, t_pac *pac)
{
	if (pac == &(d->pac_1))
	{
		return (RED);
	}
	if (pac == &(d->pac_2))
	{
		return (PINK);
	}
	if (pac == &(d->pac_3))
	{
		return (CYAN);
	}
	if (pac == &(d->pac_4))
	{
		return (ORANGE);
	}
	return (LIME);
}

void	set_root_width(t_data *d, t_pac *pac, int *x, int *y)
{
	if (pac == &(d->pac_1))
	{
		*x = 1;
		*y = 1;
	}
	if (pac == &(d->pac_2))
	{
		*x = 5;
		*y = 1;
	}
	if (pac == &(d->pac_3))
	{
		*x = 5;
		*y = 5;
	}
	if (pac == &(d->pac_4))
	{
		*x = 1;
		*y = 5;
	}
}

void	move_ghosts(t_data *d)
{
	move_ghost_type2(d, &d->pac_1);
	move_ghost_type2(d, &d->pac_2);
	move_ghost_type2(d, &d->pac_3);
	move_ghost_type2(d, &d->pac_4);
}
