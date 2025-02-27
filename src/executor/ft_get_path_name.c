/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:02:23 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:03:57 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_is_env_path(char *cmd, t_env *env_list);

char	*ft_get_path_name(char *cmd, t_env *env_list)
{
	char	*full_path;
	char	*env_path;

	if (!cmd || !env_list)
		return (NULL);
	full_path = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK))
			g_status = ft_perror(126 + (errno == 2), cmd, 0);
		else
			full_path = ft_strdup(cmd);
	}
	else
		full_path = ft_is_env_path(cmd, env_list);
	return (full_path);
}

static char	*ft_is_env_path(char *cmd, t_env *env_list)
{
	char	*env_path;
	char	*full_path;

	env_path = ft_find_env_value("PATH", env_list->var_list);
	if (!env_path)
	{
		g_status = ft_perror(127, cmd,
				"ft_get_path_name: Caminho não encontrado no PATH\n");
		return (NULL);
	}
	full_path = ft_find_relative(cmd, env_path);
	free(env_path);
	return (full_path);
}

char	*ft_handle_absolute_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) != 0)
	{
		g_status = ft_perror(126 + (errno == ENOENT), cmd, NULL);
		return (NULL);
	}
	return (ft_strdup(cmd));
}

char	*ft_find_relative(char *cmd, char *env)
{
	char	**path;
	char	*aux;
	int		i;
	char	*full_path;

	path = ft_split(env, ':');
	i = -1;
	while (path[++i])
	{
		full_path = ft_strjoin(path[i], "/");
		if (!full_path)
			break ;
		aux = ft_strjoin(full_path, cmd);
		free(full_path);
		if (aux && access(aux, F_OK | X_OK) == 0)
		{
			ft_clean_split(path);
			return (aux);
		}
		free(aux);
	}
	ft_clean_split(path);
	g_status = ft_perror(127, cmd, "command not found");
	return (NULL);
}
