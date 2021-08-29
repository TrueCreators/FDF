/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_radd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:46:26 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/04 22:50:35 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_radd(t_list **alst, t_list *new)
{
	t_list	*i;

	if (!*alst)
		*alst = new;
	else
	{
		i = *alst;
		while (i->next)
			i = i->next;
		i->next = new;
	}
}
