/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:23:51 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:23:52 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_setup_signal_handlers(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_error_handler_sigint);
}

static void	ft_error_handler_sigint(int sig)
{
	if (sig == SIGINT)
	{
		if (RL_ISSTATE(RL_STATE_READCMD))
		{
			write(STDOUT_FILENO, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
			g_status = 130;
		}
		else
		{
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			g_status = 130;
		}
	}
}
