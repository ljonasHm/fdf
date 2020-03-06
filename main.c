/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:45:48 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/02 12:45:56 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
/*
 * keys
 * A - 0
 * S - 1
 * D - 2
 * W - 13
 * esc - 53
 */
//int     ft_exit_win(int key, void **param)

int     deal_key(int key, t_fdf *fdf)
{
	if (key == 0)
		fdf->place_x -= 10;
	else if (key == 1)
		fdf->place_y += 10;
	else if (key == 2)
		fdf->place_x += 10;
	else if (key == 13)
		fdf->place_y -= 10;
	else if (key == 49 && fdf->iso == 1)
		fdf->iso = 0;
	else if (key == 49 && fdf->iso == 0)
		fdf->iso = 1;
	else if (key == 91 || key == 84)
		floors(fdf, key);
	else if (key == 69 || key == 78)
		floorge(fdf, key);
	else if (key == 53)
		exit(0);
	else if (key == 43 || key == 47)
		zoom(fdf, key);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	drawmap(fdf);
	printf("%d\n", key);
	return(0);
}

int     main(int ac, char **av)
{
	t_fdf   *fdf;
	char    *file;
	int     fd;

	if (ac == 2)
	{
		file = av[1];
		fd = open(file, O_RDONLY, 0);
		if (read(fd, NULL, 0) >= 0)
			close(fd);
		else
		{
			close(fd);
			return(error_exit(1));
		}
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		fdf->zoom = 20;
		fdf->place_x = 200;
		fdf->place_y = 200;
		fdf->iso = 1;
		fdf->floor = 1;
		fdf->floorge = 1;
		read_fdf(fdf, file);
		if (fdf->width == -1 || fdf->height == -1)
			return(error_exit_free_fdf(fdf));
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 900, "LJONAS");
		drawmap(fdf);
		mlx_key_hook(fdf->win_ptr, deal_key, fdf);
		mlx_loop(fdf->mlx_ptr);
		ft_clearintmas(fdf->mas, fdf->height);
		free(fdf);
	}
	else
		return(error_exit(0));
	return (0);
}
