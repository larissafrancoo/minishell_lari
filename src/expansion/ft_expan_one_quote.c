/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expan_one_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:06:11 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:06:31 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_expand_single_quotes(char **line)
{
	char	*str;
	int		i;
	char	*current_line;

	if (*line)
		*line += 1;
	i = 0;
	current_line = *line;
	while (current_line[i] && current_line[i] != '\'')
		i++;
	if (!current_line[i])
	{
		ft_perror(0, "syntax_error",
			" aspas simples desbalanceadas. Posição final");
		return (0);
	}
	str = ft_substr(current_line, 0, i);
	if (!str || !*str)
	{
		free(str);
		str = ft_calloc(1, 1);
	}
	*line = current_line + i + 1;
	return (str);
}
