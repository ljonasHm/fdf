/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:07:18 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/07 18:31:48 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	moduleflo(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	plus_zoom(t_cord *cords, t_fdf *fdf)
{
	cords->x *= fdf->zoom;
	cords->y *= fdf->zoom;
	cords->x1 *= fdf->zoom;
	cords->y1 *= fdf->zoom;
}

void	plus_place(t_cord *cords, t_fdf *fdf)
{
	cords->x += fdf->place_x;
	cords->y += fdf->place_y;
	cords->x1 += fdf->place_x;
	cords->y1 += fdf->place_y;
}

float	max_step(float x_step, float y_step)
{
	if (moduleflo(x_step) >= moduleflo(y_step))
		return (x_step);
	else
		return (y_step);
}

void	linedraw(t_cord cords, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	float	z;
	float	z1;

	z = fdf->mas[(int)cords.y][(int)cords.x] * fdf->floor * fdf->floorge;
	z1 = fdf->mas[(int)cords.y1][(int)cords.x1] * fdf->floor * fdf->floorge;
	plus_zoom(&cords, fdf);
	colors(fdf, z, z1);
	iso(&cords.x, &cords.y, z, fdf->iso);
	iso(&cords.x1, &cords.y1, z1, fdf->iso);
	x_step = cords.x1 - cords.x;
	y_step = cords.y1 - cords.y;
	plus_place(&cords, fdf);
	max = max_step(x_step, y_step);
	x_step /= moduleflo(max);
	y_step /= moduleflo(max);
	while ((int)(cords.x - cords.x1) || (int)(cords.y - cords.y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, cords.x, cords.y, fdf->color);
		cords.x += x_step;
		cords.y += y_step;
	}
}
