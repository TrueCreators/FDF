/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:11:12 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 15:47:24 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "math.h"
# include <fcntl.h>
# define WIN_X 1920
# define WIN_Y 1080
# define WIN_NAME "Informed Seed"
# define STEP_X 50
# define STEP_Y 50
# define STEP_Z 10
# define STEP_DEB 50
# define ROT 5

typedef enum	e_mkey
{
	MK_LEFT = 1,
	MK_RIGHT,
	MK_SCRLUP = 4,
	MK_SCRLDOWN
}				t_mkey;

typedef enum	e_keys
{
	A,
	S,
	D,
	Q = 12,
	W,
	E,
	R,
	NK_MINUS = 78,
	NK_PLUS = 69,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP,
	ESC = 53,
	ISO = 34,
	DEB = 31,
}				t_keys;

typedef struct	s_xyz
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_xyz;

typedef struct	s_map
{
	int			width;
	int			height;
	int			zoom;
	char		***temp;
	t_xyz		*vertices;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	int			shift_x;
	int			shift_y;
}				t_map;

typedef struct	s_img
{
	int			*data;
}				t_img;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;

typedef struct	s_gm
{
	int			iso:1;
	int			rot_iso:1;
	int			russia:1;
	int			menu_glb:1;
	int			menu:1;
	int			move_menu:3;
	int			settings:1;
	int			background:1;
}				t_gm;

typedef struct	s_inter
{
	int			size_x;
	int			size_y;
	int			pos_x;
	int			pos_y;
	char		*text;
	int			color_button;
	int			color_text;
}				t_inter;

typedef struct	s_glb
{
	t_win		*win;
	t_map		*map;
	t_img		*image;
	t_gm		*gm;
	t_inter		*interface;
}				t_glb;

void			error_exit(char *message);
void			usage_exit(void);

void			fdf(char *file);
void			memalloc_global(t_glb *g);
void			init_mlx(t_glb *g);
void			init_map(t_map *map, t_gm *gm);

void			parsing_map(t_map *map, char *file);

void			redraw(t_glb *g);
void			renewal(t_glb *g);
void			draw_line(t_win *win, t_map *map);
void			bresenham(t_win *win, t_xyz dot1, t_xyz dot2);
void			trans_to_iso(int *x, int *y, int *z);

void			debug(t_win *win);

int				programm_close(t_glb *g);
int				key_press(int keycode, t_glb *g);
int				mouse_press(int button, int x, int y, t_glb *g);
void			rotation_x(int *y, int *z, double angle_x);
void			rotation_y(int *x, int *z, double angle_y);
void			rotation_z(int *x, int *y, double angle_z);
void			move_rot(int keycode, t_glb *g);
void			freeall(char **splt_line, char *line);

int				get_default_color(int z, int height);
int				set_color(t_xyz curr, t_xyz start, t_xyz end, t_xyz delta);

void			create_button(t_glb *g, t_inter *inter);
void			button_pressed(int button, int x, int y, t_glb *g);
void			init_menu(t_glb *g);
void			main_menu(t_glb *g);
int				animation_menu(t_glb *g);
#endif
