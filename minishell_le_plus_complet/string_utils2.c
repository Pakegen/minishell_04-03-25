/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:08 by quenalla          #+#    #+#             */
/*   Updated: 2025/03/04 15:29:36 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	calculate_size_for_replace(const char *str, char *a, char *b)
{
	int	difference;
	int	length;

	difference = (ft_strlen(b) - ft_strlen(a)) * count_occurrences2(str, a);
	length = ft_strlen(str) + difference;
	return (length);
}

int	count_occurrences2(const char *str, char *to_find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
			count++;
		i = i + 1;
	}
	return (count);
}

void	sort_strings(char **envp, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(envp[i], envp[i + 1]) > 0)
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = 0;
		}
		else
		{
			i = i + 1;
		}
	}
}
