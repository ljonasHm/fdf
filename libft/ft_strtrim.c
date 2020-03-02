/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:54:28 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 20:00:23 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;

	if (!s)
		return (0);
	i = 0;
	while ((s[i] == 32) || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	if (s[i] == 0)
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while ((s[j] == 32) || (s[j] == '\n') || (s[j] == '\t'))
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
