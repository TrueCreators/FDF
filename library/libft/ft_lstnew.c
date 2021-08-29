/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:50 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 22:56:12 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*unreal;

	if (!(unreal = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(unreal->content = malloc(content_size)))
		{
			free(unreal);
			return (NULL);
		}
		ft_memcpy(unreal->content, content, content_size);
		unreal->content_size = content_size;
	}
	else
	{
		unreal->content = NULL;
		unreal->content_size = 0;
	}
	unreal->next = NULL;
	return (unreal);
}
