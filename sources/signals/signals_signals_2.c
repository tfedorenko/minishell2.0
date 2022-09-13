/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_signals_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:42:14 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/13 17:39:40 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_signal_handler(int sig)
{
	if (sig == SIGINT)
		exit(EXIT_FAILURE);
}

void	heredoc_signal_function(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, heredoc_signal_handler);
}
