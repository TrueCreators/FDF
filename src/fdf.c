/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:11:04 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 14:56:20 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		programm_close(t_glb *g)
{
	(void)g;
	exit(0);
	return (0);
}

void	init_mlx(t_glb *g)
{
	if (!(g->win->mlx_ptr = mlx_init()))
		error_exit("Mlx init not initialized");
	if (!(g->win->win_ptr = mlx_new_window(g->win->mlx_ptr,
					WIN_X, WIN_Y, WIN_NAME)))
		error_exit("Window not created");
}

void	init_map(t_map *map, t_gm *gm)
{
	gm->move_menu = 1;
	gm->menu_glb = 1;
	gm->menu = 1;
	gm->background = 1;
	gm->iso = 1;
	gm->rot_iso = 1;
	map->width = 0;
	map->height = 0;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->zoom = 0;
	map->shift_x = 0;
	map->shift_y = 0;
}

void	memalloc_global(t_glb *g)
{
	if (!(g->map = ft_memalloc(sizeof(t_map))))
		error_exit("t_map is not allocated");
	if (!(g->image = ft_memalloc(sizeof(t_img))))
		error_exit("t_img is not allocated");
	if (!(g->win = ft_memalloc(sizeof(t_win))))
		error_exit("t_win is not allocated");
	if (!(g->gm = ft_memalloc(sizeof(t_gm))))
		error_exit("t_win is not allocated");
	if (!(g->interface = ft_memalloc((sizeof(t_inter) * 13))))
		error_exit("g->interface is not allocated");
}

void	fdf(char *file)
{
	t_glb	*g;

	if (!(g = ft_memalloc(sizeof(t_glb))))
		error_exit("t_glb not allocated");
	memalloc_global(g);
	init_map(g->map, g->gm);
	init_mlx(g);
	parsing_map(g->map, file);
	renewal(g);
	if (g->gm->menu_glb)
	{
		main_menu(g);
		mlx_loop_hook(g->win->mlx_ptr, animation_menu, g);
	}
	mlx_hook(g->win->win_ptr, 17, 0, programm_close, (void*)0);
	mlx_hook(g->win->win_ptr, 2, 0, key_press, g);
	mlx_hook(g->win->win_ptr, 4, 0, mouse_press, g);
	mlx_loop(g->win->mlx_ptr);
}
