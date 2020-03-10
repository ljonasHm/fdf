/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:15:30 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/07 21:05:15 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		no_spcs_len(char *line)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-' && (line[i + 1] < '0' || line[i + 1] > '9'))
			return (-1);
		if (line[i] == '-' && i > 0 && line[i - 1] != ' ')
			return (-1);
		if ((line[i] < '0' || line[i] > '9')
				&& line[i] != ' ' && line[i] != '-')
			return (-1);
		if (line[i] == ' ' && i > 0 && line[i - 1] != ' ')
			n++;
		i++;
	}
	if (i > 0 && line[i - 1] != ' ')
		n++;
	return (n);
}

int		mas_in(int *mas, char *line, t_fdf *fdf)
{
	char	**numstrr;
	int		i;

	i = 0;
	numstrr = ft_strsplit(line, ' ');
	while (numstrr[i])
	{
		if (check_numstrr(numstrr[i]) == -1)
		{
			free_mas(numstrr, i);
			return (-1);
		}
		mas[i] = ft_atoi(numstrr[i]);
		if (mas[i] * fdf->floorge * fdf->floor > 5000
			|| mas[i] * fdf->floorge * fdf->floor < -5000)
			antilag(mas[i], fdf);
		free(numstrr[i]);
		i++;
	}
	free(numstrr);
	return (1);
}

void	read_hw(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;

	fdf->height = 0;
	fdf->width = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if (fdf->width == 0)
			fdf->width = no_spcs_len(line);
		else if (fdf->width != no_spcs_len(line))
			fdf->width = -1;
		fdf->height++;
		free(line);
	}
	free(line);
	close(fd);
}

void	fillmas(t_fdf *fdf, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if (mas_in(fdf->mas[i], line, fdf) == -1)
		{
			free_masfdf(fdf, i);
			fdf->width = -1;
			break ;
		}
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

void	read_fdf(t_fdf *fdf, char *file)
{
	int		i;

	i = 0;
	read_hw(file, fdf);
	if (fdf->width != -1)
	{
		if (!(fdf->mas = (int **)malloc(sizeof(int *) * fdf->height + 1)))
			fdf->width = -1;
		else
		{
			while (i < fdf->height)
			{
				if (!(fdf->mas[i] = (int *)malloc(sizeof(int)
								* (fdf->width + 1))))
				{
					free_masfdf(fdf, i);
					fdf->width = -1;
					break ;
				}
				i++;
			}
			if (fdf->width != -1)
				fillmas(fdf, file);
		}
	}
}
