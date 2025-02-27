/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:56 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 17:27:01 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_clean_cmd(t_cmd **cmd)
{
	t_cmd	*current_cmd;

	if (!cmd || !*cmd)
		return ;
	while (*cmd)
	{
		current_cmd = *cmd;
		*cmd = current_cmd->next;
		ft_clean_fd(&current_cmd->fdin);
		ft_clean_fd(&current_cmd->fdout);
		if (current_cmd->args)
			current_cmd->args = ft_clean_split(current_cmd->args);
		free(current_cmd);
	}
}
