/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:37:33 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 22:50:22 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_allfree(void **elem)
{
	size_t	i;

	i = 0;
	while ((elem)[i])
		free((elem)[i++]);
	free(elem);
	elem = NULL;
}
