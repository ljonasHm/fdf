/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:30:18 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/28 18:54:33 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlen(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	nb = (unsigned int)n;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
