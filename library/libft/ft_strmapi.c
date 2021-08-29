/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:29:22 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 14:53:58 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	if (ptr)
	{
		i = 0;
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	return (ptr);
}
