/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:51:13 by tkodai            #+#    #+#             */
/*   Updated: 2021/08/20 16:25:39 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include "mlx.h"

// ====== mac =====
# define KEY_RIGHT	65363
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_ESC	65307

# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100

# define EVENT_EXIT	33
//==================

# define BLACK		0x000000
# define LIME		0x00FF00
# define BLUE		0x2121DE
//# define BLUE		0x0000FF
# define WHITE		0xFFFFFF

# define YELLOW		0xFFFF00
# define TUMBLEWEED	0xDEA185

# define RED		0xFD0000
# define PINK		0xFFB8FF
# define CYAN		0x00FFFF
# define ORANGE		0xFFB852
# define DARK_BLUE	0x1919A6

# define UP_LEFT	1
# define UP_RIGHT	2
# define DOWN_LEFT	3
# define DOWN_RIGHT	4

/*
# define YELLOW		0xFFEB3B
# define RED		0xD50000
# define PINK		0xEC407A
# define CYAN		0x64B5F6
# define ORANGE		0xF4511E
# define DARK_BLUE	0x64B5F6
*/

/*
# define YELLOW		0xFFFF00
# define RED		0xFF0000
# define PINK		0xFF00FF
# define CYAN		0x00FFFF
# define ORANGE		0xFFA500
*/

# define TANK_1		0xF0E080 //1
# define TANK_2		0xF0A000 //2
# define TANK_3		0x606000 //3

# define CHASE		1
# define RUN		2
# define GO_BACK	3
# define NEST		4

# define INTO	1
# define HOLD	2
# define OUTOF	3

# define FRUITS_NONE	42
# define FRUITS_0		0
# define FRUITS_1		1
# define FRUITS_2		2
# define FRUITS_3		3
# define FRUITS_4		4
# define FRUITS_5		5
# define FRUITS_6		6
# define FRUITS_7		7

# define FRUITS_HIDE	0
# define FRUITS_APPEAR	1
# define FRUITS_TAKEN	2

# define TEX_PAC	1
# define TEX_GHOST	2
# define TEX_FRUITS	3
# define TEX_EXIT	4

# define MADNESS	1

# define SIZE		4

typedef struct s_data
{
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_addr;
	int		img_bit_per_pixel;
	int		img_line_lenght;
	char	*map[1000];
	int		map_width;
	int		map_height;
	int		colect_num;
	char	*xpm_addr;
	int		xpm_width;
	int		xpm_height;
	int		bits_per_pixel;
	int		line_len;
	char	*file_name;
	char	size;
	int		x_pos;
	int		y_pos;
	int		all_frame;
	int		move_count;
	int		check_player;
	int		check_escape;
	int		check_line_len;
	int		tmp42;
}				t_data;

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str, char *str2);

//ghost_pac
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);

//put_error
void	put_error(t_data *d, char *str);

//key
int		ft_key_pressed(int key, t_data *d);
void	try_move(t_data *d, int x, int y);
int		ft_key_reflect(t_data *d);
int		ft_xxx(t_data *d);

//put
void	put_map(t_data *d);
void	put_player(t_data *d);

//read_file
void	ft_read_file(t_data *d);
void	check_valid_map(t_data *d);

//xpm pixel
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
void	ft_read_xpm(t_data *d);
int		get_tex_color(t_data *d, int x, int y);
#endif
