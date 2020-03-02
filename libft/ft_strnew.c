/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:06:53 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 20:10:20 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < (size + 1))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
