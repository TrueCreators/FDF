/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:12:38 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 21:24:44 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_matrix_new(int row, int col)
{
	int		i;
	int		**matrix;

	i = 0;
	if (!(matrix = (int **)ft_calloc(sizeof(int *) * row, 0)))
		return (0);
	while (i < row)
	{
		if (!(matrix[i] = (int *)ft_calloc(sizeof(int) * col, 0)))
			return (0);
		i++;
	}
	return (matrix);
}
