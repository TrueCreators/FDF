/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:53:53 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/26 16:51:47 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	empty;
	int	i;

	count = 0;
	i = 0;
	empty = 1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
		{
			empty = 0;
			i++;
		}
		count++;
	}
	return (empty ? 0 : count);
}

static int	word_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size_tab;
	int		i;
	int		t;
	int		len;

	size_tab = count_words(s, c);
	if (!(tab = (char**)malloc((size_tab + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	t = 0;
	while (s[i])
	{
		len = 0;
		if (s[i] != c)
		{
			len = word_len(&(s[i]), c);
			if (!(tab[t] = ft_strndup(&(s[i]), word_len(&(s[i]), c))))
				return (NULL);
			t++;
		}
		i += (len ? len : 1);
	}
	tab[size_tab] = NULL;
	return (tab);
}
