/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:49:34 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/23 07:29:43 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_charlen(char const *s, char c)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		return (i);
	}
	return (0);
}

char			*ft_strchrdup(const char *s1, char c)
{
	char		*dst;
	size_t		len;

	len = ft_charlen(s1, c);
	if (!(dst = (char*)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	ft_strncpy(dst, s1, len);
	dst[len] = '\0';
	return (dst);
}
