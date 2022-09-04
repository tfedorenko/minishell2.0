/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:57:01 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/03 15:16:07 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	glob_status;

void	sigquit(int signal)
{
	if (signal != SIGQUIT)
		return ;
	glob_status = 2;
	write(2, "\\Quit: 3\n", 10);
}

void	child_sig_int(int signal)
{
	if (signal != SIGINT)
		return ;
	write (2, "^C\n", 3);
}

void sig_int(int signal)
{
	struct termios	attributes;
	struct termios	saved;
	
	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);

	attributes.c_lflag &= (~ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
	if (signal != SIGINT)
		return ;
	glob_status = ERR_ETC;
	write(1, "\033[u", 3);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	write(1, "\033[s", 3);
}

void	heredoc_sig_int(int signal)
{
	struct termios	attributes;
	struct termios	saved;

	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= (~ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
	if (signal != SIGINT)
		return ;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	glob_status = ERR_ETC;
}
