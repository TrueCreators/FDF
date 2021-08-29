/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:25:11 by sreicher          #+#    #+#             */
/*   Updated: 2019/05/01 12:22:05 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotation_x(int *y, int *z, double angle_x)
{
	int		prev_y;
	int		prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = (int)((prev_y * cos(angle_x)) + prev_z * sin(angle_x));
	*z = (int)((-prev_y * sin(angle_x)) + prev_z * cos(angle_x));
}

void		rotation_y(int *x, int *z, double angle_y)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = (int)((prev_x * cos(angle_y)) + prev_z * sin(angle_y));
	*z = (int)((-prev_x * sin(angle_y)) + prev_z * cos(angle_y));
}

void		rotation_z(int *x, int *y, double angle_z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (int)((prev_x * cos(angle_z)) - prev_y * sin(angle_z));
	*y = (int)((prev_x * sin(angle_z)) + prev_y * cos(angle_z));
}
