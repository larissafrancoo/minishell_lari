/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:19 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 17:26:22 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(char **args, t_env *env)
{
	(void)args;
	g_status = 0;
	if (!env)
		return ;
	if (!env->pwd)
	{
		free(env->pwd);
		env->pwd = getcwd(NULL, 0);
		if (env->pwd)
			printf("%s\n", env->pwd);
		else
		{
			g_status = 1;
			perror("getcwd");
		}
	}
	else
		printf("%s\n", env->pwd);
}
