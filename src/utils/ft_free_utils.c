/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorshhe <emorshhe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:28:18 by emorshhe          #+#    #+#             */
/*   Updated: 2025/02/19 20:28:20 by emorshhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_clean_split(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**ft_free_splterr(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (*(split)[i])
	{
		free(split[i]);
		i++;
	}
	return (0);
}
