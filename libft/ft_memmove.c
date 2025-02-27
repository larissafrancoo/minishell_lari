/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:40:10 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 22:40:12 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tdest;
	const unsigned char	*tsrc;

	tdest = (unsigned char *)dest;
	tsrc = (const unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	else if (dest < src)
		while (n--)
			*tdest++ = *tsrc++;
	else
		while (n--)
			tdest[n] = tsrc[n];
	return (dest);
}
