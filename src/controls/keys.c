/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:16:21 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 15:47:37 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotation(int keycode, t_glb *g)
{
	if (keycode == UP)
		g->map->angle_x += 0.05;
	else if (keycode == RIGHT)
		g->map->angle_y -= 0.05;
	else if (keycode == LEFT)
		g->map->angle_y += 0.05;
	else if (keycode == DOWN)
		g->map->angle_x -= 0.05;
	else if (keycode == Q)
		g->map->angle_z -= 0.05;
	else if (keycode == E)
		g->map->angle_z += 0.05;
	redraw(g);
}

static void		move(int keycode, t_glb *g)
{
	if (keycode == A)
		g->map->shift_x -= 100;
	else if (keycode == D)
		g->map->shift_x += 100;
	else if (keycode == W)
		g->map->shift_y -= 100;
	else if (keycode == S)
		g->map->shift_y += 100;
	else if (keycode == NK_MINUS)
		g->map->zoom -= 2;
	else if (keycode == NK_PLUS)
		g->map->zoom += 2;
	redraw(g);
}

static void		gamemode(int keycode, t_glb *g)
{
	if (keycode == ISO)
		g->gm->iso = (g->gm->iso + 1) % 2;
	if (keycode == DEB)
		g->gm->rot_iso = (g->gm->rot_iso + 1) % 2;
	if (keycode == R)
		g->gm->russia = (g->gm->russia + 1) % 2;
	redraw(g);
}

int				mouse_press(int button, int x, int y, t_glb *g)
{
	button_pressed(button, x, y, g);
	return (0);
}

int				key_press(int keycode, t_glb *g)
{
	if (keycode == ESC)
		programm_close(g);
	if (keycode == W || keycode == S
	|| keycode == D || keycode == A
	|| keycode == NK_MINUS || keycode == NK_PLUS)
		move(keycode, g);
	else if (keycode == UP || keycode == DOWN
	|| keycode == LEFT || keycode == RIGHT
	|| keycode == Q || keycode == E)
		rotation(keycode, g);
	else if (keycode == DEB || keycode == ISO
	|| keycode == R)
		gamemode(keycode, g);
	return (0);
}
