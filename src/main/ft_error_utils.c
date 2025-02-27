/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:20:15 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:20:16 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	else_perror(char *msg, char *text, int i)
{
	if (!msg)
		perror(text);
	else if (!(msg[i] == '%' && msg[i + 1] != '\0'))
		ft_putchar_fd(msg[i], 2);
}

/*
	else
		ft_putchar_fd(msg[i], 2);
*/

int	ft_perror(int ret, char *text, char *msg, ...)
{
	va_list	apt;
	int		i;

	ft_print_message("bash", text, msg);
	if (msg)
	{
		va_start(apt, msg);
		i = -1;
		while (msg[++i])
		{
			if (msg[i] == '%' && msg[i + 1] != '\0')
			{
				if (msg[i + 1] == 's')
					ft_putstr_fd(va_arg(apt, char *), 2);
				else if (msg[i + 1] == 'c')
					ft_putchar_fd((char)va_arg(apt, int), 2);
				i++;
			}
			else_perror(msg, text, i);
		}
		ft_putchar_fd('\n', 2);
		va_end(apt);
	}
	else_perror(msg, text, i);
	return (ret);
}

void	ft_print_message(char *shell, char *text, char *msg)
{
	if (shell != NULL)
	{
		ft_putstr_fd(shell, 2);
		if (text && *text)
		{
			ft_putstr_fd(": ", 2);
			if (msg)
				ft_putstr_fd(text, 2);
		}
		if (msg && *msg)
			ft_putstr_fd(": ", 2);
	}
}

t_cmd	*ft_command_error(t_fd *in, t_fd *out, char **split)
{
	split = ft_clean_split(split);
	ft_clean_fd(in);
	ft_clean_fd(out);
	return (0);
}

int	ft_lex_error(char c, int n)
{
	if (!c)
		g_status = ft_perror(2, "lexer",
				"erro de sintaxe: token inesperado 'newline' encontrado");
	else if (c == '|')
		g_status = ft_perror(2, "lexer",
				"erro de sintaxe: uso incorreto do operador pipe '|'");
	else if (c == '<' || c == '>')
		g_status = ft_perror(2, "lexer",
				"erro de sintaxe: redirecionamento inválido '%c'", c);
	else if (ft_isspace(c))
		g_status = ft_perror(2, "lexer",
				"erro de sintaxe: espaço extra não esperado antes do token");
	else
		g_status = ft_perror(2, "lexer",
				"erro de sintaxe: operador inválido '%c' encontrado", c);
	return (0);
}
