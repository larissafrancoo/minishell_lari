/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:24:40 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:24:44 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_check_alloc(void *str, char *text)
{
	if (str == NULL)
	{
		errno = ENOMEM;
		ft_perror(0, text, 0);
	}
	return (str);
}
