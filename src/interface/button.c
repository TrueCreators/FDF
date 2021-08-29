/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 08:59:56 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 11:16:01 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_button(t_glb *g, t_inter *inter)
{
	int	i;
	int	j;

	inter->pos_x = inter->pos_x - (inter->size_x / 2);
	inter->pos_y = inter->pos_y - (inter->size_y / 2);
	i = -1;
	while (++i < inter->size_x)
	{
		j = -1;
		while (++j < inter->size_y)
			mlx_pixel_put(g->win->mlx_ptr, g->win->win_ptr, inter->pos_x + i,
			inter->pos_y + j, inter->color_button);
	}
	if (inter->text)
		mlx_string_put(g->win->mlx_ptr, g->win->win_ptr,
		inter->pos_x + (inter->size_x / 2) - (ft_strlen(inter->text) * 5),
		inter->pos_y + (inter->size_y / 2) - 10,
		inter->color_text, inter->text);
}
