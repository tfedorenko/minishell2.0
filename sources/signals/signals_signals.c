/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:52:26 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/12 18:34:57 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_proc_sig_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	}	
	if (sig == SIGINT)
		ft_putchar_fd('\n', STDOUT_FILENO);
}	

void	sigint_handler(int sig)
{
	if (sig)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_redisplay();
	}
}

// void heredoc_signal_handler(int sig)
// {
// 	if (sig == SIGINT)
// 		exit(1);
// }

// void heredoc_signal_function(void)
// {
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGINT, heredoc_signal_handler);	
// }

void	signals_function(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

void	signals_function_cat(void)
{
	signal(SIGQUIT, child_proc_sig_handler);
	signal(SIGINT, child_proc_sig_handler);
}
