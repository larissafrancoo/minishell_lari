/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:01:16 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:01:25 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_executor(t_shell *shell)
{
	t_cmd	*cmd;
	int		builtin;
	int		original_pipe;

	if (!shell || !shell->cmd)
		return ;
	cmd = shell->cmd;
	if ((!cmd->next) && ft_is_builtin(*shell->cmd->args))
	{
		ft_builtin_exec(shell, cmd);
		return ;
	}
	original_pipe = dup(0);
	process_command_pipeline(original_pipe, shell, cmd);
}
