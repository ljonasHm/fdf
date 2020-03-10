/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:39:23 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/07 20:24:32 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_numstrr(char *numstrr)
{
	char *str;

	if (numstrr[0] == '-' && ft_atoi(numstrr) > 0)
		return (-1);
	if (numstrr[0] != '-' && ft_atoi(numstrr) < 0)
		return (-1);
	str = ft_itoa(ft_atoi(numstrr));
	if (ft_strcmp(str, numstrr) != 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (1);
}

void	checklag(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->mas[i][j] * fdf->floor * fdf->floorge > 5000
					|| fdf->mas[i][j] * fdf->floor * fdf->floorge < -5000)
				antilag(fdf->mas[i][j], fdf);
			j++;
		}
		i++;
	}
}
