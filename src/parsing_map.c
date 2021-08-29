/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:49:03 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/27 15:53:35 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			one_string(char *file)
{
	int		fd;
	char	**sp_line;
	char	*nw_line;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		error_exit("File not exist");
	get_next_line(fd, &nw_line);
	sp_line = ft_strsplit(nw_line, ' ');
	while (sp_line[i])
	{
		free(sp_line[i]);
		i++;
	}
	if (i != 0)
		free(nw_line);
	free(sp_line);
	close(fd);
	return (i);
}

static void			lenght_xy(char fd, t_map *map, char *file)
{
	char	**splt_line;
	int		x_pos;
	char	*new_line;
	int		y_pos;
	int		x_prev;

	y_pos = 0;
	x_prev = one_string(file);
	if (x_prev == 0)
		error_exit("No file or no map");
	while ((get_next_line(fd, &new_line)))
	{
		splt_line = ft_strsplit(new_line, ' ');
		x_pos = 0;
		while (splt_line[x_pos])
			x_pos++;
		if (x_prev != x_pos)
			error_exit("No valid file");
		freeall(splt_line, new_line);
		y_pos++;
	}
	map->width = x_pos;
	map->height = y_pos;
	if (y_pos < 1 || x_pos != map->width || !new_line)
		error_exit("Bad lines");
}

static void			map_to_array(char fd, t_map *map)
{
	int		i;
	char	*new_line;

	i = 0;
	map->temp = ft_memalloc(sizeof(char **) * map->height);
	while ((get_next_line(fd, &new_line) > 0))
	{
		map->temp[i] = ft_strsplit(new_line, ' ');
		free(new_line);
		i++;
	}
}

static void			init_map_content(t_map *map)
{
	int		i;

	i = 0;
	map->vertices = (t_xyz *)malloc(map->width * map->height * sizeof(t_xyz));
	while (i < map->width * map->height)
	{
		map->vertices[i].x = i % map->width;
		map->vertices[i].y = i / map->width;
		map->vertices[i].z = ft_atoi(map->temp[i / map->width][i % map->width]);
		map->vertices[i].color = 0x00FF00;
		i++;
	}
	if (map->height < map->width)
		map->zoom = (WIN_X / 2) / map->height + 1;
	else
		map->zoom = (STEP_X / 2) / map->width + 2;
}

void				parsing_map(t_map *map, char *file)
{
	int		fd;
	int		fd2;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_exit("File not exist");
	if ((fd2 = open(file, O_RDONLY)) == -1)
		error_exit("File not exist");
	lenght_xy(fd2, map, file);
	map_to_array(fd, map);
	init_map_content(map);
}
