/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:36:38 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 08:58:21 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				draw_line(t_win *win, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				bresenham(win, (map->vertices[y * map->width + x]),
						(map->vertices[y * map->width + x + 1]));
			if (y + 1 < map->height)
				bresenham(win, (map->vertices[y * map->width + x]),
						(map->vertices[(y + 1) * map->width + x]));
			x++;
		}
		y++;
	}
}

static void			zoom_color(t_glb *g, int *x, int *y, int *color)
{
	if (g->map->zoom == 0)
		g->map->zoom = 1;
	if (g->gm->russia)
		*color = get_default_color(*y, g->map->height);
	else
		*color = 0x00FF00;
	*x *= g->map->zoom;
	*y *= g->map->zoom;
	*x -= g->map->width * g->map->zoom / 2;
	*y -= g->map->height * g->map->zoom / 2;
	g->map->zoom = abs(g->map->zoom);
}

static void			iso(t_glb *g, int *x, int *y, int *z)
{
	if (g->gm->iso)
	{
		if (g->gm->rot_iso)
		{
			g->map->angle_x = 0;
			g->map->angle_y = 0;
			g->map->angle_z = 0;
		}
		trans_to_iso(x, y, z);
	}
}

void				redraw(t_glb *g)
{
	mlx_clear_window(g->win->mlx_ptr, g->win->win_ptr);
	renewal(g);
	if (g->gm->menu_glb)
		main_menu(g);
}

void				renewal(t_glb *g)
{
	int i;

	i = -1;
	while (++i < g->map->width * g->map->height)
	{
		g->map->vertices[i].x = i % g->map->width;
		g->map->vertices[i].y = i / g->map->width;
		zoom_color(g, &g->map->vertices[i].x, &g->map->vertices[i].y,
		&g->map->vertices[i].color);
		iso(g, &g->map->vertices[i].x, &g->map->vertices[i].y,
		&g->map->vertices[i].z);
		rotation_x(&g->map->vertices[i].y, &g->map->vertices[i].z,
		g->map->angle_x);
		rotation_y(&g->map->vertices[i].x, &g->map->vertices[i].z,
		g->map->angle_y);
		rotation_z(&g->map->vertices[i].x, &g->map->vertices[i].y,
		g->map->angle_z);
		g->map->vertices[i].x += g->map->shift_x;
		g->map->vertices[i].y += g->map->shift_y;
		g->map->vertices[i].x += WIN_X / 2;
		g->map->vertices[i].y += WIN_Y / 2;
		g->map->vertices[i].z = ft_atoi(g->map->temp[i / g->map->width]
		[i % g->map->width]) * STEP_Z - g->map->zoom;
	}
	draw_line(g->win, g->map);
}
