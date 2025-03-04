/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:49:55 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 15:34:21 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_env(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		ft_printf("%s\n", temp->content);
		temp = temp->next;
	}
}

void	write_export(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		ft_printf("declare -x %s\n", temp->content);
		temp = temp->next;
	}
}
