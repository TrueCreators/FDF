/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:38:11 by sreicher          #+#    #+#             */
/*   Updated: 2019/04/23 07:31:46 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list		*get_list(t_list **alst, int fd)
{
	t_list			*temp;

	temp = *alst;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(alst, temp);
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	ssize_t			byte;
	void			*temp;
	static t_list	*alst;
	t_list			*list;

	ERROR(fd, line, read(fd, buffer, 0));
	CHECK((list = get_list(&alst, fd)));
	while ((byte = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[byte] = '\0';
		JOINFR(temp, list->content, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (byte < BUFF_SIZE && ft_strlen(list->content) == 0)
		return (0);
	CHECK((*line = ft_strchrdup(list->content, '\n')));
	if (ft_strchr(list->content, '\n'))
	{
		FRESH(temp, list->content, ft_strchr(temp, '\n') + 1);
	}
	else
		ft_strclr(list->content);
	return (1);
}
