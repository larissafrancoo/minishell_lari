/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:22:18 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:22:19 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_input(char *line, t_shell *shell)
{
	char	**args;
	t_cmd	*no;
	int		i;

	if (!line || !*line)
		return ;
	args = ft_split_with_set(line, "|");
	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		no = ft_init_and_process_command(args[i], shell);
		if (!no)
		{
			ft_clean_cmd(&shell->cmd);
			break ;
		}
		ft_cmd_append(&shell->cmd, no);
		i++;
	}
	args = ft_clean_split(args);
}
