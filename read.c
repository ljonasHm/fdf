/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:15:30 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/02 12:15:33 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     read_height(char *file)
{
	ft_putstr(file);
	return (0);
}

void    read_fdf(t_fdf *fdf, char *file)
{
	fdf->height = read_height(file);
}