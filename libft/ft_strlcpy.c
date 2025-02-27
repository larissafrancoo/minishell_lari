/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:43:24 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:43:27 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*srct;
	char	*dstt;
	size_t	i;

	srct = (char *)src;
	dstt = dst;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && size - 1 > i)
	{
		dstt[i] = srct[i];
		i++;
	}
	dstt[i] = '\0';
	return (ft_strlen(src));
}
