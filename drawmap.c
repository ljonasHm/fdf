/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:40:40 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/07 20:09:18 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawpix(t_fdf *fdf)
{
	int z;

	z = fdf->mas[0][0];
	if (z > 0)
		fdf->color = 0xe80c0c;
	else
		fdf->color = 0xFFFFF;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
			fdf->place_x, fdf->place_y, fdf->color);
}

void	zoom(t_fdf *fdf, int key)
{
	if (key == 43)
		fdf->zoom -= 1;
	else if (key == 47)
		fdf->zoom += 1;
	if (fdf->zoom < 0)
		fdf->zoom = 0;
}

void	floors(t_fdf *fdf, int key)
{
	if (key == 91)
		fdf->floor += 1;
	else if (key == 84)
		fdf->floor -= 1;
}

void	floorge(t_fdf *fdf, int key)
{
	if (key == 78)
		fdf->floorge *= 0.9;
	if (key == 69)
		fdf->floorge /= 0.9;
}

void	drawmap(t_fdf *fdf)
{
	t_cord	cords;

	if (fdf->height == 1 && fdf->width == 1)
		drawpix(fdf);
	else
	{
		cords.y = 0;
		while (cords.y < fdf->height)
		{
			cords.x = 0;
			while (cords.x < fdf->width)
			{
				cords.x1 = cords.x + 1;
				cords.y1 = cords.y;
				if (cords.x < fdf->width - 1)
					linedraw(cords, fdf);
				cords.x1--;
				cords.y1++;
				if (cords.y < fdf->height - 1)
					linedraw(cords, fdf);
				cords.x++;
			}
			cords.y++;
		}
	}
}
