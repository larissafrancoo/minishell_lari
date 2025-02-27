/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:44:29 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:44:33 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (s1[i] && i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
