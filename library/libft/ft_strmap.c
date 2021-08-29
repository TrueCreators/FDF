/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:09:17 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 19:51:45 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ptr[i] = f(s[i]);
			i++;
		}
	}
	return (ptr);
}
