/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:22:38 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:22:39 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_configure_redirections(char *input, t_fd *fd, t_shell *shell)
{
	int		j;
	char	symbol;
	int		i;

	i = -1;
	while (input[++i])
	{
		j = 0;
		i += ft_find_quote_end(&input[i]);
		if (input[i] && (input[i] == '<') || (input[i] == '>'))
		{
			symbol = input[i];
			while (input[i + j] && input[i + j] == symbol)
				j++;
			i = i + j;
			if (symbol == '<')
				if (ft_input_redir(&input[i], fd, j, shell) < 0)
					return (-1);
			if (symbol == '>')
				if (ft_output_redir(&input[i], fd, j, shell) < 0)
					return (-1);
		}
	}
	return (0);
}

int	ft_input_redir(char *fname, t_fd *fd, int op, t_shell *shell)
{
	t_fd	temp_fd;

	if ((fd[IN].ffd == -1) || (fd[OUT].ffd == -1))
	{
		if (op == 2)
		{
			temp_fd.fnm = ft_set_filename(fname, shell);
			if (!temp_fd.fnm)
				return (-1);
			temp_fd.ffd = ft_heredoc(temp_fd.fnm);
			ft_clean_fd(&temp_fd);
		}
		return (0);
	}
	ft_clean_fd(&fd[IN]);
	fd[IN].fnm = ft_set_filename(fname, shell);
	if (!fd[IN].fnm)
		return (-1);
	if (op == 1)
		fd[IN].ffd = open(fd[IN].fnm, O_RDONLY, 00644);
	else if (op == 2)
		fd[IN].ffd = ft_heredoc(fd[IN].fnm);
	return (0);
}

int	ft_output_redir(char *fname, t_fd *fd, int op, t_shell *shell)
{
	if ((fd[IN].ffd != -1) && (fd[OUT].ffd != -1))
	{
		ft_clean_fd(&fd[OUT]);
		fd[OUT].fnm = ft_set_filename(fname, shell);
		if (!fd[OUT].fnm)
			return (-1);
		if (op == 1)
			fd[OUT].ffd = open(fd[OUT].fnm, O_WRONLY | O_CREAT | O_TRUNC,
					00644);
		else if (op == 2)
			fd[OUT].ffd = open(fd[OUT].fnm, O_WRONLY | O_CREAT | O_APPEND,
					00644);
	}
	return (0);
}

char	*ft_set_filename(char *input, t_shell *shell)
{
	char	*temp;
	char	*filename;
	char	quote_type;
	int		i;

	i = 0;
	while (ft_isspace(*input))
		input++;
	if ((input[i] == '\'') || (input[i] == '\"'))
	{
		quote_type = input[i];
		i++;
		while (input[i] != quote_type)
			i++;
		i++;
	}
	else
		while (input[i] && !ft_strchr("<>| \t\n\v\r\f", input[i]))
			i++;
	temp = ft_substr(input, 0, i);
	filename = ft_expand_variables(temp, shell->argv, shell->env->var_list);
	free(temp);
	return (ft_check_alloc(filename, "set_filename"));
}
