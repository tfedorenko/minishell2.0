/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:38:47 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/12 15:39:47 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "minishell.h"
// #include "system/environment.h"
// #include "read/line.h"

#include "Libft/libft.h"
#include "stdio.h"
#include <stdlib.h> 

/*void rl_replace_line (const char *text, int clear_undo)
Replace the contents of rl_line_buffer with text. 
The point and mark are preserved, if possible. 
If clear_undo is non-zero, 
the undo list associated with the current line is cleared.*/

/*/int rl_on_new_line (void)
Tell the update functions that we have moved onto a new (empty) line, 
usually after outputting a newline.*/

/* void rl_redisplay (void)
Change what's displayed on the screen to reflect 
the current contents of rl_line_buffer. */

static void	sigint_handler(int sig)
{
	if (sig)
	{
		// rl_replace_line("", 0);
		// rl_on_new_line();
		// ft_putchar_fd('\n', STDOUT_FILENO);
		print_prompt("minishell$ ");
		// rl_redisplay();
	}
}

static void	signals_function(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

int	main(int argc, char const *argv[], char *const *env)
{
	char	*cmd;

	signals_function();
	while (1)
	{
		cmd = read_next_command();
		if (!cmd)
			exit(0);
		if (cmd[0] == '\0' || ft_strncmp(cmd, "\n", 1) == 0)
		{
			free(cmd);
			continue ;
		}
		if (ft_strncmp(cmd, "exit", 4) == 0)
		{
			free(cmd);
			break ;
		}
		write(1, cmd, ft_strlen(cmd));
		free(cmd);
	}
	// env_variables(env);
	return (0);
}
