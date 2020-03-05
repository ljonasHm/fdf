/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:05:02 by ljonas            #+#    #+#             */
/*   Updated: 2019/09/26 18:44:58 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_skip_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	return (i);
}

static size_t	ft_words(char const *str, char c)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		if (*str != c)
		{
			words++;
			while (*str != c && *str)
				str++;
		}
		if (*str == c)
		{
			while (*str == c && *str)
				str++;
		}
	}
	return (words);
}

static size_t	ft_wlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void		*ft_free_arr(char **arr, size_t i)
{
	size_t j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		arr[j] = NULL;
		j++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str;

	if (s == NULL || !(str = (char **)malloc(sizeof(char*)
					* (ft_words(s, c) + 1))))
		return (NULL);
	j = -1;
	i = ft_skip_c(s, c);
	while (++j < ft_words(s, c) && s[i] != '\0')
	{
		i = i + ft_skip_c(s + i, c);
		if (!(str[j] = (char *)malloc(sizeof(char) * (ft_wlen(s + i, c) + 1))))
			return (ft_free_arr(str, j));
		k = -1;
		while (s[i] != c && s[i] != '\0')
			str[j][++k] = s[i++];
		str[j][++k] = '\0';
	}
	str[j] = NULL;
	return (str);
}
