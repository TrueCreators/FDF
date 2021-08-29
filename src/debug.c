/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:50:40 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/26 16:50:44 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		middle_line(t_win *win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (WIN_X) || j < (WIN_Y))
	{
		if (i < (WIN_X))
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, i, (WIN_Y / 2), 0xff0000);
		if (j < (WIN_Y))
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, (WIN_X / 2), j, 0x008000);
		i++;
		j++;
	}
}

static void		dot_screen(t_win *win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i * j < (WIN_Y / 2) * (WIN_X / 2))
	{
		if (i * STEP_DEB > WIN_X)
		{
			i = 0;
			j++;
		}
		if (i * STEP_DEB < (WIN_X))
			mlx_pixel_put(win->mlx_ptr, win->win_ptr,
					i * STEP_DEB, j * STEP_DEB, 0xFFFFFF);
		i++;
	}
}

void			debug(t_win *win)
{
	middle_line(win);
	dot_screen(win);
}
