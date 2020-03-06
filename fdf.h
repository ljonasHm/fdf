/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:50:07 by ljonas            #+#    #+#             */
/*   Updated: 2020/02/15 15:55:00 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h> //forbidden

typedef struct  s_fdf
{
	int     width;
	int     height;
	int     **mas;
	int     zoom;
	int     color;
	int     place_x;
	int     place_y;
	int     iso;
	int     floor;
	float   floorge;
	
	void    *mlx_ptr;
	void    *win_ptr;
}               t_fdf;

int     deal_key(int key, t_fdf *fdf);
void    read_fdf(t_fdf *fdf, char *file);
void    read_hw(char *file, t_fdf *fdf);
void    read_fdf(t_fdf *fdf, char *file);
int     error_exit(int error);
int     error_exit_free_fdf(t_fdf *fdf);
int     no_spcs_len(char *line);
int     mas_in(int *mas, char *line, t_fdf *fdf);
void    ft_clearintmas(int **mas, int height);
void    linedraw(float x, float y, float x1, float y1, t_fdf *fdf);
float   moduleflo(float x);
void    drawmap(t_fdf *fdf);
void    drawpix(t_fdf *fdf);
void    iso(float *x, float *y, float z);
void    zoom(t_fdf *fdf, int key);
void    floors(t_fdf *fdf, int key);
void    floorge(t_fdf *fdf, int key);
int     check_numstrr(char *numstrr);
void    free_masfdf(t_fdf *fdf, int i);
void    free_mas(char **mas, int i);
void    antilag(int num, t_fdf *fdf);

#endif
