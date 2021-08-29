/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:39:00 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 14:27:17 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				animation_menu(t_glb *g)
{
	if (g->gm->background)
	{
		if (g->map->zoom <= 150 && g->gm->move_menu)
			g->map->zoom += 1;
		if (g->map->zoom >= 140)
			g->gm->move_menu = 0;
		if (g->gm->move_menu == 0)
			g->map->zoom -= 1;
		if (g->map->zoom <= 20)
			g->gm->move_menu = 1;
		redraw(g);
	}
	return (0);
}
