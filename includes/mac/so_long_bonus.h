/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:51:13 by tkodai            #+#    #+#             */
/*   Updated: 2022/05/18 22:12:28 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include "mlx.h"

# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_ESC	53
# define KEY_PLUS	24
# define KEY_MINUS	27

# define KEY_U		32
# define KEY_M		46
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_4		21
# define KEY_5		23
# define KEY_6		22
# define KEY_7		26
# define KEY_8		28
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2

# define EVENT_EXIT	17

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
# define COLOR_42	0x00BABC

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

# define MADNESS	1

# define SIZE		2

# define ANIME_PAC			1	
# define ANIME_PAC_BIG		2
# define ANIME_GHOST1		3
# define ANIME_GHOST_RUN	4
# define ANIME_PILE			5
# define ANIME_GHOST2		6
# define ANIME_GHOST3		7

# define EAT_TIME			150
# define MOVE_SPEED			250

# define DEFAULT_SPEED		32000

# define VALID_CHEAT		1

typedef struct s_hass_mass
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		up_left;
	int		up_right;
	int		down_left;
	int		down_right;
}				t_mass;

typedef struct s_outframe
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		tmp42;
}				t_outframe;

typedef struct s_fruits
{
	int		dx;
	int		dy;
	int		dy_dist;
	int		dx_dist;
	int		stack[7];
	int		stack_num;
	int		put_mode;
	int		put_count;
	int		put_70;
	int		put_140;	
}				t_fruits;

typedef struct s_xy
{
	int		x;
	int		y;
}				t_xy;

typedef struct s_tex
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		color;
	int		x;
	int		y;
}				t_tex;

typedef struct s_queue_data
{
	int					x;
	int					y;
	struct s_queue_data	*next;
	struct s_queue_data	*prev;
}				t_queue_data;

typedef struct s_queue
{
	t_queue_data	*head;
	t_queue_data	*tail;
}				t_queue;

typedef struct s_pac
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		move_dx;
	int		move_dy;
	int		tag_x;
	int		tag_y;
	int		status;
	int		sprite_count;
	int		nest_status;
	int		blue_time;
	int		vanish_count;
	int		init_x;
	int		init_y;
	int		init_dy;
	int		init_dx;
	int		dir_x;
	int		dir_y;
	int		dist;
	int		home_pos_dx;
	int		home_pos_dy;
	int		color;
	int		move_dist;
	int		type;
	int		nest_dx;
	int		nest_dy;
	int		cb_tex;
	int		tmp42;
}				t_pac;

typedef struct s_key
{
	int		up;
	int		down;
	int		left;
	int		right;
}				t_key;

typedef struct s_tab
{
	int		tmp;
}				t_tab;

typedef struct s_nest
{
	int		door1_x;
	int		door1_y;
	int		door2_x;
	int		door2_y;
	double	door_c_x;
	int		door_c_y;
	t_pac	*p1;
	t_pac	*p2;
	t_pac	*p3;
	t_pac	*p4;
	int		count;
	int		scramble;
}				t_nest;

typedef struct s_cb
{
	t_pac	pac1;
	t_pac	pac2;
	t_pac	pac3;
	t_pac	pac4_2;
	t_pac	pac4_3;
	t_pac	pac4_4;
	int		coffee;
	int		frame;
	int		valid_x;
	int		start_y;
	int		end_y;
	int		start_x;
	int		end_x;
	int		stage_frame;
	int		logo_w;
	int		logo_h;
	int		pile;
	int		add_y;

	int		start_y2;
	int		end_y2;
	int		start_x2;
	int		end_x2;
	int		logo_w2;
	int		logo_h2;

}				t_cb;

typedef struct s_data
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*img_addr;
	int			img_bit_per_pixel;
	int			img_line_lenght;
	char		*map[1000];
	char		*map_pellet[1000];
	char		*map_pellet_og[1000];
	int			pellet_num;
	int			pellet_num_og;
	int			map_width;
	int			map_height;
	int			**dotmap;
	int			size;
	int			size_set;
	int			bfs_map[200][200];
	t_pac		pac_mine;
	t_pac		pac_1;
	t_pac		pac_2;
	t_pac		pac_3;
	t_pac		pac_4;
	int			show_root;
	t_key		key;
	int			order_1;
	int			order_2;
	int			executed;
	int			frame;
	int			all_frame;
	t_nest		nest;
	int			first_key_press;
	int			score;
	int			high_score;
	int			life_score;
	int			game_set;
	int			stage_count;
	int			stage_frame;
	char		*xpm_addr;
	int			xpm_width;
	int			xpm_height;
	int			bits_per_pixel;
	int			line_len;
	char		*xpm_addr_c[4];
	int			xpm_width_c[4];
	int			xpm_height_c[4];
	int			bits_per_pixel_c[4];
	int			line_len_c[4];
	char		*xpm_addr2;
	int			xpm_width2;
	int			xpm_height2;
	int			bits_per_pixel2;
	int			line_len2;
	int			madness;
	int			eat_stop_count;
	int			eat_time;
	int			eat_streak;
	int			eat_std_time;
	int			life_stock;
	int			game_set_count;
	int			clear_flag;
	int			move_count;
	int			move_count_d;
	int			move_count_is_valid;
	t_fruits	fruits;	
	char		*file_name;
	int			sleep_count;
	t_cb		cb;
	int			tmp42;
	int			repaint;
}				t_data;

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s, char *s2);

//ghost_pac
void	move_ghosts(t_data *d);
void	init_bfs_map(t_data *d);

//pixelputs

void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
void	my_mlx_pixel_put_og(t_data *d, int x, int y, int color);
void	put_dot_3(t_data *d, int tab_x, int tab_y, t_pac *pac);

//ghost_pac_type2
void	move_ghost_type2(t_data *d, t_pac *pac);
int		pac_on_branch(t_data *d, t_pac *pac);

//type2
void	get_target(t_data *d, t_pac *pac);
void	get_target_patrol(t_data *d, t_pac *pac);
void	move_pac_follow_move_xy(t_data *d, t_pac *pac);

//map
void	ft_generate_dotmap(t_data *d);
void	set_xy(t_xy *xy, int x, int y);
void	set_edge(t_data *d, int *x, int *y, t_xy *xy);
void	shape_init_mass(t_mass *mass);

void	shape_set_status(t_data *d, int x, int y, t_mass *mass);
void	shape_put_cross(t_data *d, int x, int y);
void	shape_diago_up(t_data *d, int x, int y);
void	shape_diago_down(t_data *d, int x, int y);
void	shape_up_down(t_data *d, int x, int y, t_mass *mass);
void	shape_right_left(t_data *d, int x, int y, t_mass *mass);
void	shape_kill_pillar(t_data *d, int x, int y, t_mass *mass);
void	shape_kill_fill_mass(t_data *d, int x, int y, t_mass *mass);
void	shape_make_edge1(t_data *d, int x, int y, t_mass *mass);
void	shape_make_edge2(t_data *d, int x, int y, t_mass *mass);

//repaint
void	repaint_map(t_data *d);

//map_nest
void	generate_nest(t_data *d);
void	generate_nest_make_frame(t_data *d);

//
void	put_dotpac(t_data *d);
void	put_dotghost(t_data *d, t_pac *pac, int color);

//put_eye
int		get_madness_eye(t_data *d, t_pac *pac, int x, int y);
int		ret_eye_color(t_data *d, t_pac *pac, int x, int y);

//put_body
int		ret_body_color_type2(t_data *d, t_pac *pac, int x, int y);
int		ret_body_color_type1(t_data *d, t_pac *pac, int x, int y);

//read
void	ft_read_file(t_data *d);
void	check_line(t_data *d, char *line, int index);

//score
void	put_life(t_data *d);
void	put_high_score_num(t_data *d);
void	put_score_num(t_data *d);
void	my_mlx_pixel_put_top(t_data *d, int x, int y, int color);
void	put_score_logo(t_data *d);

//nest
void	ft_nest(t_data *d, t_pac *pac);
void	nest_hold(t_data *d, t_pac *pac);
void	nest_outof(t_data *d, t_pac *pac);
void	nest_into(t_data *d, t_pac *pac);

//xpm
void	ft_read_xpm(t_data *d);
int		get_tex_color(t_data *d, int x, int y);
int		get_tex_color2(t_data *d, int x, int y);
int		get_tex_color3(t_data *d, int x, int y, int i);

//logo
void	put_start_logo(t_data *d);
void	put_end_logo(t_data *d);

//logo
void	put_score(t_data *d);

//score
void	read_high_score(t_data *d);
void	write_high_score(t_data *d);

//kill
void	put_kill_ghost_score(t_data *d);

//continue
void	ft_continue(t_data *d, int num);

//init
void	ft_init_pac(t_data *d, t_pac *pac, int x, int y);

//dying
void	pacman_dying(t_data *d);

//window
void	ft_clear_window(t_data *d);
void	real_clear(t_data *d);

//set_pellet
void	ft_set_pellet(t_data *d);

void	pac_patrol(t_data *d, t_pac *pac);

//set_move_dir_ver2
void	set_move_dir_ver2(t_data *d, t_pac *pac);
void	show_target(t_data *d, t_pac *pac, int color);

//out_frame
void	put_out_frame(t_data *d);
void	put_outframe1(t_data *d, t_outframe *oframe);
void	set_outframe(t_data *d, t_outframe *oframe);
void	put_dotmap_edge(t_data *d, t_xy pos, int sign);
void	gen_pathway_space(t_data *d, int x, int y);
void	fix_path_row(t_data *d, int x);
void	gen_pathway_edge_down(t_data *d, int x, int y, int sign);
void	gen_pathway_edge_up(t_data *d, int x, int y, int sign);
void	put_fixed_path(t_data *d, int x, int y);

//fruits
void	ft_fruits(t_data *d);
void	init_fruits(t_data *d, t_fruits *fruits);
void	level_up_fruits(t_data *d, t_fruits *fruits);
int		ret_fruits(int statge);
int		ret_fruits_score(int stage);

//fruits2
void	put_fruits_logo(t_data *d, t_fruits *fruits);
void	put_fruits_map2(t_data *d, t_fruits *f);

//coffee
void	ft_coffee_break(t_data *d);
void	put_fruits_logo(t_data *d, t_fruits *f);
void	init_coffee(t_data *d);
void	get_move_dist(t_data *d);
void	set_logo_size(t_data *d);
void	put_cb_pac_type1(t_data *d);
void	put_cb_pac_type2(t_data *d);
void	put_cb_pac_type3(t_data *d);
void	put_cb_pac_type4(t_data *d);
//coffee2
void	put_cb_pac3(t_data *d, t_pac *pac);
void	put_cb_logo(t_data *d, int type);
void	put_cb_logo_2(t_data *d, int type, int i);
void	put_cb_pac4(t_data *d, t_pac *pac);
void	put_cb_pac6(t_data *d, t_pac *pac);
void	put_cb_pac2(t_data *d, t_pac *pac);
int		is_inside_window(t_data *d, int x, int y);
int		is_black(t_data *d, int x, int y);

//eat_pellet
void	ft_eat_pellet(t_data *d);

//pacman
void	ft_move_pac(t_data *d);

//dotmap
void	ft_put_dotmap(t_data *d);

//cookie
void	put_dot(t_data *d);

//ft_action
void	ft_solong_act(t_data *d);
void	move_jump_pac(t_data *d, t_pac *pac);
void	fixed_blue2(t_data *d, t_pac *pac);
void	fixed_blue(t_data *d);
void	eat_stop_count(t_data *d);

//init pac
void	ft_init_pac(t_data *d, t_pac *pac, int x, int y);

//cheat
void	ft_key_pressed_cheat(int key, t_data *d);

//key
int		ft_key_pressed(int key, t_data *d);
int		ft_reflect_key(t_data *d);
int		ft_key_released(int key, t_data *d);
int		ft_error(t_data *d, int error_type);

//inits
void	ft_solong_init_3(t_data *d);
void	ft_solong_init_2(t_data *d);
void	ft_solong_init_1(t_data *d);

//coffee
void	set_anime_color(t_data *d, t_tex *tex);
void	set_anime_tex(t_data *d, t_pac *pac, t_tex *tex);

#endif
