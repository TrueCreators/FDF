/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:10:59 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 13:17:04 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *message)
{
	if (!message)
		ft_putstr("Error");
	else
	{
		ft_putstr("Error: ");
		ft_putendl(message);
	}
	exit(-1);
}

void	ft_allfree(void **elem)
{
	size_t	i;

	i = 0;
	while ((elem)[i])
		free((elem)[i++]);
	free(elem);
	elem = NULL;
}

void	freeall(char **splt_line, char *line)
{
	ft_allfree((void **)splt_line);
	free(line);
}

void	usage_exit(void)
{
	ft_putstr_fd("./fdf usage: ./fdf youmap.fdf", 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		fdf(argv[1]);
	}
	else
		usage_exit();
}
