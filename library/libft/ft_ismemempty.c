/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismemempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:26:56 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 23:32:38 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ismemempty(void *mem, size_t n)
{
	while (n--)
		if (((unsigned char*)mem)[n])
			return (0);
	return (1);
}
