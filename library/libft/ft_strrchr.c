/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:37:13 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/15 15:09:46 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*rev;

	rev = s;
	while (*rev)
	{
		rev++;
	}
	if (c == '\0')
		return ((char*)rev);
	while (rev >= s)
	{
		if (*rev == (const char)c)
			return ((char *)rev);
		rev--;
	}
	return (NULL);
}
