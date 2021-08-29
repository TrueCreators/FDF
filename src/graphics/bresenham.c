/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:31:40 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/26 16:34:59 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_win *win, t_xyz dot1, t_xyz dot2)
{
	t_xyz			delta;
	t_xyz			sign;
	int				error[2];

	delta.x = abs(dot2.x - dot1.x);
	delta.y = abs(dot2.y - dot1.y);
	sign.x = dot1.x < dot2.x ? 1 : -1;
	sign.y = dot1.y < dot2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, dot2.x, dot2.y, dot1.color);
	while (dot1.x != dot2.x || dot1.y != dot2.y)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, dot1.x, dot1.y, dot1.color);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			dot1.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			dot1.y += sign.y;
		}
	}
}
