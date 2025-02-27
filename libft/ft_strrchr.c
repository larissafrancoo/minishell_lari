/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:45:07 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:45:09 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*temps;
	int				i;
	unsigned char	tempc;

	temps = (char *)s;
	i = ft_strlen(s);
	tempc = (unsigned char)c;
	while (i >= 0)
	{
		if (temps[i] == tempc)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
