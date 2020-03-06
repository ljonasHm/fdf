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

void    iso(float *x, float *y, float z)
{
	float px;
	float py;
	
	px = *x;
	py = *y;
	*x = (px - py) * cos(0.523599);
	*y = -z + (px + py) * sin(0.523599);
}

void    linedraw(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float   x_step;
	float   y_step;
	float   max;
	float   z;
	float   z1;
	
	z = fdf->mas[(int)y][(int)x] * fdf->floor * fdf->floorge;
	z1 = fdf->mas[(int)y1][(int)x1] * fdf->floor * fdf->floorge;
	x *= fdf->zoom;
	y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
	if (z > 0 || z1 > 0)
		fdf->color = 0xe80c0c;
	else
		fdf->color = 0xFFFFF;
	if (fdf->iso == 1)
	{
		iso(&x, &y, z);
		iso(&x1, &y1, z1);
	}
	x_step = x1 - x;
	y_step = y1 - y;
	x += fdf->place_x;
	y += fdf->place_y;
	x1 += fdf->place_x;
	y1 += fdf->place_y;
	if (moduleflo(x_step) >= moduleflo(y_step))
		max = x_step;
	else
		max = y_step;
	x_step /= moduleflo(max);
	y_step /= moduleflo(max);
	while ((int)(x - x1) || (int)(y - y1))
    {
	    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
	    x += x_step;
	    y += y_step;
    }
}