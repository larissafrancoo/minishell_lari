/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:49 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 17:27:51 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cleanup_pid(t_pid *head)
{
	t_pid	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_cleanup_shell_resources(t_shell *shell)
{
	t_cmd	*cmd;
	t_cmd	*next_cmd;
	int		i;

	if (shell->argv)
		free(shell->argv);
	cmd = shell->cmd;
	while (cmd)
	{
		next_cmd = cmd->next;
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				i++;
			}
			if (cmd->args)
				free(cmd->args);
		}
		free(cmd);
		cmd = next_cmd;
	}
}

void	ft_cleanup_resources(t_shell *shell, t_pid *pd, int *fd, t_env *env)
{
	if (pd)
		ft_cleanup_pid(pd);
	if (fd)
		ft_cleanup_fd(fd);
	if (shell)
		ft_cleanup_shell_resources(shell);
	if (env)
		ft_cleanup_env(env);
}

void	ft_clean_sh(t_shell *shell)
{
	close(shell->fd[IN]);
	close(shell->fd[OUT]);
	ft_clean_cmd(&shell->cmd);
}
