/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:16:58 by qacjl             #+#    #+#             */
/*   Updated: 2025/02/28 15:24:30 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n\033[0;32mminishell> \033[0m", 23);
}

void	handle_sigquit(int sig)
{
	(void)sig;
	write(1, "\b\b \b\b", 8);/*a refaire*/
}

void	setup_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
