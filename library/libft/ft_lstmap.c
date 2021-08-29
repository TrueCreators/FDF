/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:49:42 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 20:51:05 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstmap;
	t_list *ptr;

	if (lst == NULL || f == NULL)
		return (NULL);
	lstmap = f(lst);
	if (lstmap == NULL)
		return (NULL);
	ptr = lstmap;
	while (lst->next)
	{
		lst = lst->next;
		ptr->next = f(lst);
		if (ptr->next == NULL)
			return (NULL);
		ptr = ptr->next;
	}
	return (lstmap);
}
