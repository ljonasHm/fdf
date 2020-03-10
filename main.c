/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:45:48 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/07 21:14:26 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		filecheck(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY, 0);
	if (read(fd, NULL, 0) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}

void	fdfinit(t_fdf *fdf)
{
	fdf->zoom = 20;
	fdf->place_x = 200;
	fdf->place_y = 200;
	fdf->iso = 1;
	fdf->floor = 1;
	fdf->floorge = 1;
}

void	pick_iso(t_fdf *fdf)
{
	if (fdf->iso == 0)
		fdf->iso = 1;
	else
		fdf->iso = 0;
}

int		deal_key(int key, t_fdf *fdf)
{
	if (key == 0)
		fdf->place_x -= 10;
	else if (key == 1)
		fdf->place_y += 10;
	else if (key == 2)
		fdf->place_x += 10;
	else if (key == 13)
		fdf->place_y -= 10;
	else if (key == 48)
		fdfinit(fdf);
	else if (key == 49)
		pick_iso(fdf);
	else if (key == 91 || key == 84)
		floors(fdf, key);
	else if (key == 69 || key == 78)
		floorge(fdf, key);
	else if (key == 53)
		exit(0);
	else if (key == 43 || key == 47)
		zoom(fdf, key);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	checklag(fdf);
	drawmap(fdf);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		if (filecheck(av[1]) == -1)
			return (error_exit(1));
		if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
			return (error_exit(2));
		fdfinit(fdf);
		read_fdf(fdf, av[1]);
		if (fdf->width == -1 || fdf->height == -1)
			return (error_exit_free_fdf(fdf));
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "LJONAS");
		drawmap(fdf);
		mlx_key_hook(fdf->win_ptr, deal_key, fdf);
		mlx_loop(fdf->mlx_ptr);
		ft_clearintmas(fdf->mas, fdf->height);
		free(fdf);
	}
	else
		return (error_exit(0));
	return (0);
}
