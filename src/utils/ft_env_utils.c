/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:28:05 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:28:06 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_find_env(char *key, char **env)
{
	int	i;
	int	key_len;

	if (!key || !env)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(key, env[i], key_len) == 0 && env[i][key_len] == '=')
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*ft_find_env_value(char *key, char **env)
{
	char	*var;

	var = ft_find_env(key, env);
	if (var)
		return (ft_strdup(ft_strchr(var, '=') + 1));
	return (NULL);
}
