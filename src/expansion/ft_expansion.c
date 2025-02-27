/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:16:34 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:16:37 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_expand_variables(char *input, char **args, char **env)
{
	char	*result;
	char	*temp;

	if (!input)
	{
		return (NULL);
	}
	result = NULL;
	while (*input)
	{
		if (*input == '$')
			temp = ft_expand_env_variable(&input, args, env);
		else if (*input == '\"')
			temp = ft_expand_double_quotes(&input, args, env);
		else if (*input == '\'')
			temp = ft_expand_single_quotes(&input);
		else
			temp = ft_expand_plain_text(&input, "$\'\"");
		result = ft_merge_strings(result, temp);
	}
	return (result);
}
