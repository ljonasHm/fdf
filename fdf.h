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

typedef struct  s_fdf
{
	int     width;
	int     height;
	int     **mas;
	
	void    *mlx_ptr;
	void    *win_ptr;
}               t_fdf;

int     deal_key(int key, void **param);
void    read_fdf(t_fdf *fdf, char *file);
int     read_height(char *file);
void    error_exit(int error);
int     no_spcs_len(char *line);

#endif
