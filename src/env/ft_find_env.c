/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:04:56 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 19:05:00 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_get_env(char *key, char **env)
{
	int	i;
	int	key_len;

	if (!env || !key)
		return (NULL);
	i = -1;
	key_len = ft_strlen(key);
	while (env[++i])
	{
		if (ft_strncmp(env[i], key, key_len) == 0 && (key[key_len - 1] == '='
				|| env[i][key_len] == '='))
			return (env[i]);
	}
	return (NULL);
}
