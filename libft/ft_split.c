/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:41:21 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:41:24 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static void	ft_free(size_t i, char **strs)
{
	while (i > 0)
	{
		i--;
		free(strs[i]);
	}
	free(strs);
}

static char	**split(char const *str, char c, char **strs, size_t wordc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < wordc)
	{
		while (str[j] && str[j] == c)
			j++;
		strs[i] = ft_substr(str, j, ft_word_len(&str[j], c));
		if (strs[i] == NULL)
		{
			ft_free(i, strs);
			return (NULL);
		}
		while (str[j] && str[j] != c)
			j++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	nstr;

	if (s == NULL)
		return (NULL);
	nstr = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (nstr + 1));
	if (strs == NULL)
		return (NULL);
	strs = split(s, c, strs, nstr);
	return (strs);
}
