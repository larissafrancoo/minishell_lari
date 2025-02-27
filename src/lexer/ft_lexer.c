/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:18:54 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 21:43:01 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_lexer(char *line)
{
	if (!line || !*line)
		return (0);
	if (!ft_check_closed_op(line))
		return (0);
	if (!ft_check_pipe_syntax(line))
		return (0);
	if (!ft_check_redir_syntax(line, '<'))
		return (0);
	if (!ft_check_redir_syntax(line, '>'))
		return (0);
	return (1);
}

int	ft_check_closed_op(char *str)
{
	char	quote_type;
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\'') || (str[i] == '\"'))
		{
			quote_type = str[i];
			i++;
			while (str[i] && (str[i] != quote_type))
				i++;
			if (!str[i])
				return (ft_lex_error(str[i], 1));
		}
		i++;
	}
	return (1);
}

int	ft_check_pipe_syntax(char *str)
{
	int	first_cmd;
	int	i;

	first_cmd = 0;
	i = 0;
	while (str[i])
	{
		i += ft_find_quote_end(&str[i]);
		if (!str[i])
			return (ft_lex_error(str[i], 2));
		if (!first_cmd && (!ft_isspace(str[i]) && (str[i] != '|')))
			first_cmd = 1;
		if (str[i] == '|')
		{
			if (!first_cmd)
				return (ft_lex_error(str[i], 3));
			first_cmd = 0;
		}
		i++;
	}
	if (!first_cmd)
		return (ft_lex_error(str[i], 4));
	return (first_cmd);
}

static int	isspecial(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	ft_check_redir_syntax(char *str, char opt)
{
	int	redir;
	int	i;
	int	num;

	num = ft_strlen(str);
	i = -1;
	while (str[++i] && i < num)
	{
		redir = 0;
		if (str[i] == '\'' || str[i] == '\"')
			i += ft_find_quote_end(&str[i]) + 1;
		else if (str[i] == opt)
		{
			while ((str[i + redir] == opt) && (redir < 4) && (i + redir < num))
				redir++;
			if (redir > 2)
				return (ft_lex_error(str[i], 5));
			i += redir;
			while (ft_isspace(str[i]))
				i++;
			if (str[i] == '\0' || isspecial(str[i]))
				return (ft_lex_error(str[i], 6));
		}
	}
	return (1);
}
