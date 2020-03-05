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
	float   x_dif;
	float   y_dif;
	float   max;

	x_dif = x1 - x;
	y_dif = y1 - y;
    printf("xy %f %f %f\n", x_step, y_step, y_step/x_step);
	if (moduleflo(x_dif) >= moduleflo(y_dif))
    {
	    x_step = 1;
	    y_step = (float)y_dif/(float)x_dif;
	    printf("y - %f\n", y_step);
    }
	else
    {
	    x_step = x_dif/y_dif;
	    y_step = 1;
    }
	printf("xy %f %f\n", x_step, y_step);
	while ((int)(x - x1) || (int)(y - y1))
    {
	    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
	    x += x_step;
	    y += y_step;
    }
    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
}