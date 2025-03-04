/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:49:33 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 15:28:22 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i = i + 1;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strndup(const char *src, size_t n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin2(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		total_size;
	char	*new_string;

	i = 0;
	total_size = 0;
	while (i < size)
	{
		total_size = total_size + ft_strlen(strs[i]);
		if (i < size - 1)
			total_size = total_size + ft_strlen(sep);
		i = i + 1;
	}
	new_string = malloc(sizeof(char) * (total_size + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(new_string + j, strs[i]);
		j = j + ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(new_string + j, sep);
			j = j + ft_strlen(sep);
		}
		i = i + 1;
	}
	new_string[total_size] = '\0';
	return (new_string);
}

char	*replace(const char *str, char *a, char *b)
{
	int		i;
	int		size;
	int		total_size;
	char	*new_string;

	i = 0;
	total_size = calculate_size_for_replace(str, a, b);
	new_string = malloc(sizeof(char) * (total_size + 1));
	if (!new_string)
		return (NULL);
	while (*str)
	{
		if (ft_strncmp(str, a, ft_strlen(a)) == 0)
		{
			size = 0;
			while (b[size])
			{
				new_string[i] = b[size];
				i = i + 1;
				size = size + 1;
			}
			str = str + ft_strlen(a);
		}
		else
		{
			new_string[i] = *str;
			i = i + 1;
			str++;
		}
	}
	new_string[i] = '\0';
	return (new_string);
}

