/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:55:00 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 14:53:28 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	lenght;

	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	ptr = NULL;
	if (start + len <= lenght)
	{
		ptr = ft_strnew(len);
		if (ptr)
		{
			ptr = ft_strncpy(ptr, s + start, len);
			ptr[len] = '\0';
		}
	}
	return (ptr);
}
