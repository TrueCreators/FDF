/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:21:23 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 22:59:17 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_list_to_array(t_list *lst)
{
	size_t			size_elem;
	size_t			nb_elem;
	size_t			i;
	unsigned char	*array;

	i = 0;
	size_elem = lst->content_size;
	nb_elem = ft_list_count(lst);
	if (!(array = ft_memalloc(nb_elem * size_elem)))
		return (NULL);
	while (i < nb_elem)
	{
		ft_memcpy(&(array[i * size_elem]), lst->content, size_elem);
		lst = lst->next;
		i++;
	}
	return (array);
}
