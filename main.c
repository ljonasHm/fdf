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

int main (int ac, char **av)
{
	t_fdf   *fdf;
	char    *file;
	int     i;
	int     j;

	if (ac == 2)
	{
		file = av[1];
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		read_fdf(fdf, file);
		ft_putnbr(fdf->height);
		ft_putchar('\n');
		ft_putnbr(fdf->width);
		ft_putchar('\n');
		i = 0;
		while (i < fdf->height)
        {
		    j = 0;
		    while (j < fdf->width)
            {
		        printf("%3d", fdf->mas[i][j]);
		        j++;
            }
		    printf("\n");
		    i++;
        }
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 900, "LJONAS");
        linedraw(10, 10, 300, 600, fdf);
//		mlx_key_hook(fdf->win_ptr, deal_key, NULL);
		mlx_loop(fdf->mlx_ptr);
		ft_clearintmas(fdf->mas, fdf->height);
		free(fdf);
//		mlx_loop(fdf->mlx_ptr);
	}
	else
		error_exit(0);
	return (0);
}
