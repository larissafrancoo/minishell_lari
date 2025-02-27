/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:22:54 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:22:55 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_find_quote_end(char *str)
{
	int		i;
	char	quote_char;

	if (!str)
		return (0);
	i = 0;
	quote_char = str[i];
	if (str[i] == '\'' || str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != quote_char)
			i++;
		if (str[i] == quote_char)
			return (i);
	}
	return (0);
}
