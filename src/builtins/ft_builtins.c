/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:23:48 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 17:36:03 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_status = 0;

void	ft_execute_builtins(char **args, t_env *env, t_shell *shell)
{
	if (ft_strncmp(args[0], "echo", 5) == 0)
		ft_echo(args);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		ft_cd(args, env);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		ft_pwd(args, env);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		ft_export(args, env);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		ft_unset(args, env);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		ft_env(env);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		ft_exit(args, env, shell);
}

void	ft_builtin_exec(t_shell *shell, t_cmd *cmd)
{
	if (!confirm(cmd))
		return ;
	ft_setfd(STDIN_FILENO, &cmd->fdin, STDIN_FILENO);
	ft_setfd(STDOUT_FILENO, &cmd->fdout, STDOUT_FILENO);
	ft_execute_builtins(cmd->args, shell->env, shell);
	dup2(shell->fd[0], STDIN_FILENO);
	dup2(shell->fd[1], STDOUT_FILENO);
}

int	ft_is_builtin(char *cmd)
{
	int			i;
	const char	*builtins[8];

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strncmp(builtins[i], cmd, ft_strlen(builtins[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}
