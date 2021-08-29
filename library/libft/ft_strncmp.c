/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:52:41 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/15 16:32:33 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	while (*string1 == *string2 && *string1 != '\0' && n > 0)
	{
		string1++;
		string2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*string1 - *string2);
}
