/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:28:36 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 12:19:55 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_to_iso(int *x, int *y, int *z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (int)((prev_x - prev_y) * cos(0.523599));
	*y = (int)((prev_x + prev_y) * sin(0.523599) - *z);
}
