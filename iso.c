/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:55:34 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/07 20:00:32 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(float *x, float *y, float z, int iso)
{
	float px;
	float py;

	if (iso == 1)
	{
		px = *x;
		py = *y;
		*x = (px - py) * cos(0.523599);
		*y = -z + (px + py) * sin(0.523599);
	}
}