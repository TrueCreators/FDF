/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:18:24 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 14:53:02 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f'
			|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		len;

	if (s == NULL || !s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_space(s[len - 1]))
		len--;
	i = -1;
	while (ft_space(s[++i]))
		len--;
	if (len <= 0)
		len = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		ptr[i] = *s++;
	ptr[i] = '\0';
	return (ptr);
}
