/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:07:18 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/05 18:07:19 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float   moduleflo(float x)
{
	if (x < 0)
		return(-x);
	return(x);
}

void    linedraw(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float   x_step;
	float   y_step;
	int     max;
	
	x_step = x1 - x;
	y_step = y1 - y;
}