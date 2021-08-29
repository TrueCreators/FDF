/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 08:27:59 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 08:29:11 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_default_color(int z, int height)
{
	int	sector_draw;

	sector_draw = height / 3;
	if (z < sector_draw)
		return (0xFFFFFF);
	else if (z < sector_draw * 2)
		return (0x0000FF);
	else
		return (0xFF0000);
}
