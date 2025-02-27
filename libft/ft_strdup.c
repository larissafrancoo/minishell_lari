/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:42:03 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:42:06 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*src2;
	char			*new_str;
	char			*pointer;
	unsigned int	count;

	src2 = (char *)src;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	count = ft_strlen(src);
	if (!new_str)
		return (NULL);
	pointer = new_str;
	while (count--)
	{
		*new_str++ = *src2++;
	}
	*new_str = '\0';
	return (pointer);
}
