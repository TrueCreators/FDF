/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:16:25 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 15:52:02 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		button_menu_canvas(int button, int x, int y, t_glb *g)
{
	if (button == MK_LEFT && x >= WIN_X - 250 - (250 / 2) &&
	x <= WIN_X - 250 + (250 / 2) &&
	y >= WIN_Y / 2 - (50 / 2) - 200 && y <= WIN_Y / 2 + (50 / 2) - 200)
	{
		g->gm->menu_glb = 0;
		g->gm->background = 0;
	}
	if (button == MK_LEFT && x >= WIN_X - 250 - (250 / 2) &&
	x <= WIN_X - 250 + (250 / 2) &&
	y >= WIN_Y / 2 - (50 / 2) - 100 && y <= WIN_Y / 2 + (50 / 2) - 100)
	{
		g->gm->menu = 0;
	}
	if (button == MK_LEFT && x >= WIN_X - 250 - (250 / 2) &&
	x <= WIN_X - 250 + (250 / 2) &&
	y >= WIN_Y / 2 - (50 / 2) && y <= WIN_Y / 2 + (50 / 2))
	{
		g->gm->menu = 0;
		g->gm->settings = 1;
	}
	if (button == MK_LEFT && x >= WIN_X - 250 - (250 / 2) &&
	x <= WIN_X - 250 + (250 / 2) &&
	y >= WIN_Y / 2 - (50 / 2) + 100 && y <= WIN_Y / 2 + (50 / 2) + 100)
		programm_close(g);
	redraw(g);
}

static void		button_settings_canvas(int button, int x, int y, t_glb *g)
{
	if (button == MK_LEFT && x >= WIN_X / 2 - (150 / 2) - 200 &&
	x <= WIN_X / 2 + (150 / 2) - 200 &&
	y >= WIN_Y / 2 - (50 / 2) + 200 && y <= WIN_Y / 2 + (50 / 2) + 200)
	{
		g->gm->settings = 0;
		g->gm->menu = 1;
		redraw(g);
	}
}

void			button_pressed(int button, int x, int y, t_glb *g)
{
	if (g->gm->menu && button == MK_LEFT)
		button_menu_canvas(button, x, y, g);
	if (g->gm->settings && button == MK_LEFT)
		button_settings_canvas(button, x, y, g);
}
