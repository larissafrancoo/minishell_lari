/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:25:31 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 19:01:04 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_env *env)
{
	t_env	*current;
	int		i;

	if (!env || !env->var_list)
	{
		g_status = 1;
		return (EXIT_FAILURE);
	}
	current = env;
	i = -1;
	while (current->var_list[++i])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		ft_putstr_fd(current->var_list[i], STDOUT_FILENO);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	g_status = 0;
	return (EXIT_SUCCESS);
}
