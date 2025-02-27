/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:41:34 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:41:37 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*temps;
	int				i;
	unsigned char	tempc;

	temps = (char *)s;
	i = 0;
	tempc = (unsigned char)c;
	while (temps[i] != '\0')
	{
		if (temps[i] == tempc)
			return ((char *)&s[i]);
		i++;
	}
	if ((!c))
		return (&temps[i]);
	return (NULL);
}
