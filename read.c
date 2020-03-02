/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:15:30 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/02 12:15:33 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     no_spcs_len(char *line)
{
	int i;
	int n;
	
	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			n++;
			
		i++;
	}
	return (n);
}

int     read_height(char *file)
{
	int     fd;
	int     height;
	char    *line;
	
	height = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int     read_width(char *file)
{
	int     fd;
	char    *line;
	int     width;
	
	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = no_spcs_len(line);
	free(line);
	close(fd);
	return (width);
}

void    read_fdf(t_fdf *fdf, char *file)
{
	fdf->height = read_height(file);
	fdf->width = read_width(file);
}