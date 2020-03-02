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

/*
 * keys
 * A - 0
 * S - 1
 * D - 2
 * W - 13
 * esc - 53
 */
//int     ft_exit_win(int key, void **param)

int main (int ac, char **av)
{
	t_fdf   *fdf;
	char    *file;
	if (ac == 2)
	{
		file = av[1];
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		read_fdf(fdf, file);
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 500, 500, "mlx42");
		mlx_loop(fdf->mlx_ptr);
	}
	else
		error_exit(0);
	return (0);
}
