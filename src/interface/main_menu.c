/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:31:51 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 15:54:29 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_settings(t_glb *g)
{
	(g->interface)[4] = (t_inter) {150, 50, WIN_X / 2 - 200, WIN_Y / 2 - 200,
	"CONTROLS", 0xFFFFFF, 0};
	(g->interface)[5] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2 - 200,
	"INPUT                            DESCRIPTION", 0xFFFFFF, 0};
	(g->interface)[6] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2 - 150,
	"W, A, S, D                        Move Camera", 0xFFFFFF, 0};
	(g->interface)[7] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2 - 100,
	" ARROWS, Q, E                  Rotate Figure XYZ", 0xFFFFFF, 0};
	(g->interface)[8] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2 - 50,
	"R                                 RUSSIA MODE", 0xFFFFFF, 0};
	(g->interface)[9] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2,
	" I                               ISO/PERSP mode", 0xFFFFFF, 0};
	(g->interface)[10] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2 + 50,
	"  O                               ISO rotate mode", 0xFFFFFF, 0};
	(g->interface)[11] = (t_inter) {500, 50, WIN_X / 2 + 200, WIN_Y / 2 + 100,
	"NUM +, NUM -                             Zoom", 0xFFFFFF, 0};
	(g->interface)[12] = (t_inter) {150, 50, WIN_X / 2 - 200, WIN_Y / 2 + 200,
	"<- BACK", 0xFFFFFF, 0};
}

void			init_menu(t_glb *g)
{
	(g->interface)[0] = (t_inter) {250, 50, WIN_X - 250, WIN_Y / 2 - 200,
	"PLAY", 0xFFFFFF, 0};
	(g->interface)[1] = (t_inter) {250, 50, WIN_X - 250, WIN_Y / 2 - 100,
	"ANIMATION MODE", 0xFFFFFF, 0};
	(g->interface)[2] = (t_inter) {250, 50, WIN_X - 250, WIN_Y / 2,
	"SETTINGS", 0xFFFFFF, 0};
	(g->interface)[3] = (t_inter) {250, 50, WIN_X - 250, WIN_Y / 2 + 100,
	"EXIT", 0xFFFFFF, 0};
	init_settings(g);
}

static void		menu_text(t_glb *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		create_button(g, &g->interface[i]);
}

static void		settings(t_glb *g)
{
	int	i;

	i = 3;
	while (++i < 13)
		create_button(g, &g->interface[i]);
}

void			main_menu(t_glb *g)
{
	init_menu(g);
	if (g->gm->menu)
		menu_text(g);
	if (g->gm->settings)
		settings(g);
}
