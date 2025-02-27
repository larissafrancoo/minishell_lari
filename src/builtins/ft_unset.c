/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:30 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 17:33:27 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_validate_identifier(char *identifier)
{
	int	i;

	i = 0;
	if (!identifier || !(ft_isalpha(identifier[0]) || identifier[0] == '_'))
	{
		printf("unset: `%s': not a valid identifier\n", identifier);
		g_status = 1;
		return (1);
	}
	while (identifier[i])
	{
		if (!(ft_isalnum(identifier[i]) || identifier[i] == '_'))
		{
			printf("unset: `%s': not a valid identifier\n", identifier);
			g_status = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_remove_environment_variable(t_env *env, int index)
{
	int	i;

	i = index;
	while (env->var_list[i])
	{
		env->var_list[i] = env->var_list[i + 1];
		i++;
	}
}

int	ft_search_equal(t_env *env, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (env->var_list[i])
	{
		if (!ft_strncmp(env->var_list[i], str, len)
			&& env->var_list[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_unset(char **args, t_env *env)
{
	int	i;
	int	index;

	i = 0;
	g_status = 0;
	while (args[i])
	{
		if (!ft_validate_identifier(args[i]))
		{
			index = ft_search_equal(env, args[i]);
			if (index != -1)
				ft_remove_environment_variable(env, index);
		}
		i++;
	}
}
