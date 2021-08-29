/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:44:14 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 23:32:47 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

t_list		*ft_strsplit_list(char const *s, char c)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	int		len;

	i = 0;
	lst = NULL;
	while (s[i])
	{
		len = 0;
		if (s[i] != c)
		{
			len = word_len(&(s[i]), c);
			if (!(tmp = ft_lstnew(ft_strndup(&(s[i]), len), len)))
				return (NULL);
			ft_list_radd(&lst, tmp);
		}
		i += (len ? len : 1);
	}
	return (lst);
}
