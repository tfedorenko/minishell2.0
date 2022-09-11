/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:52:26 by tfedoren          #+#    #+#             */
/*   Updated: 2022/09/11 16:24:25 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_prompt(char *text)
// {
// 	printf(text);
// }


void child_proc_sig_handler(int sig)
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

// void	sig_handler_cat(int sig)
// {
// 	// printf("here2 = %i\n", sig);
// 	if (sig)
// 	{
// 		// rl_replace_line("", 0);
// 		// rl_on_new_line();
		
// 		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
// 		// write(1, "Quit: 3\n", 8);
// 		// exit(1);
// 		// rl_redisplay();
	// }
// }

// void	sigint_handler_cat(void)
// {
// 	signal(SIGQUIT, child_proc_sig_handler);
// 	signal(SIGINT, child_proc_sig_handler);
// }

// void	child_sig_function(void)
// {
// 	signal(SIGQUIT, child_proc_sig_handler);
// 	signal(SIGINT, child_proc_sig_handler);
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
	// printf("here1\n");
}
