/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:43:33 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/02 12:43:59 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	error_exit(int error)
{
	if (error == 0)
		ft_putstr("usage: ./fdf source_file\n");
	if (error == 1)
		ft_putstr("invalid file\n");
	return(0);
}

int     error_exit_free_fdf(t_fdf *fdf)
{
	free(fdf);
	ft_putstr("invalid file\n");
	return(0);
}

void    free_masfdf(t_fdf *fdf, int i)
{
	while(i < fdf->height)
	{
		free(fdf->mas[i]);
		i++;
	}
	free(fdf->mas);
}

void    free_mas(char **mas, int i)
{
	while(mas[i])
	{
		free(mas[i]);
		i++;
	}
	free(mas);
}

void    antilag(int num, t_fdf *fdf)
{
	while ((num * fdf->floorge) > 5000 || (num * fdf->floorge) < -5000)
		floorge(fdf, 78);
}