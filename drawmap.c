/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:40:40 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/06 11:40:43 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    drawpix(t_fdf *fdf)
{
	int z;
	
	z = fdf->mas[0][0];
	if (z > 0)
		fdf->color = 0xe80c0c;
	else
		fdf->color = 0xFFFFF;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->place_x, fdf->place_y, fdf->color);
}

void    zoom(t_fdf *fdf, int key)
{
	if (key == 43)
		fdf->zoom -= 1;
	else if (key == 47)
		fdf->zoom += 1;
	if (fdf->zoom < 0)
		fdf->zoom = 0;
}

void    floors(t_fdf *fdf, int key)
{
	if (key == 91)
		fdf->floor += 1;
	else if (key == 84)
		fdf->floor -= 1;
}

void    floorge(t_fdf *fdf, int key)
{
	if (key == 78)
		fdf->floorge *= 0.9;
	if (key == 69)
		fdf->floorge /= 0.9;
}

void    drawmap(t_fdf *fdf)
{
	float x;
	float y;
	
	if (fdf->height == 1 && fdf->width == 1)
		drawpix(fdf);
	else
	{
		y = 0;
		while (y < fdf->height)
		{
			x = 0;
			while (x < fdf->width)
			{
				if (x < fdf->width - 1)
					linedraw(x, y, x + 1, y, fdf);
				if (y < fdf->height - 1)
					linedraw(x, y, x, y + 1, fdf);
				x++;
			}
			y++;
		}
	}
}