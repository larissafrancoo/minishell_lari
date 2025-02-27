/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:25:06 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 19:00:16 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	new_line;
	int	j;

	i = 0;
	new_line = 1;
	while (args[++i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		j = ft_count_n(args, i);
		if (args[i][j] != '\0')
			break ;
		new_line = 0;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[++i])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (new_line)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (g_status = 0);
}

int	ft_count_n(char **args, int i)
{
	int	count;

	count = 1;
	while (args[i][count] == 'n')
		count++;
	return (count);
}
