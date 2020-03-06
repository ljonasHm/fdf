/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:39:23 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/06 20:39:25 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     check_numstrr(char *numstrr)
{
	if (numstrr[0] == '-' && ft_atoi(numstrr) > 0)
		return (-1);
	if (numstrr[0] != '-' && ft_atoi(numstrr) < 0)
		return (-1);
	return (1);
}