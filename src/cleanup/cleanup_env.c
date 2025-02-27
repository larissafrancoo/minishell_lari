/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:27 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 17:29:20 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cleanup_env(t_env *env)
{
	int	i;

	i = 0;
	if (env->var_list)
	{
		while (env->var_list[i])
		{
			free(env->var_list[i]);
			i++;
		}
		free(env->var_list);
	}
	if (env->pwd)
		free(env->pwd);
}
