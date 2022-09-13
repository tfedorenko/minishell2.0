/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:22:51 by rkultaev          #+#    #+#             */


#include "../../includes/minishell.h"

extern int	glob_status;

int	write_to_temp_file(char *heredoc_str)
{
	int		fd;

	fd = open(".heredoc.tmp", O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd == ERROR)
		return (ERROR);
	write(fd, heredoc_str, ft_strlen(heredoc_str));
	close(fd);
	return (SUCCESS);
}

char	*fetch_heredoc_str(char *heredoc_str, char *read_line)
{
	char	*tmp;

	tmp = read_line;
	read_line = ft_strjoin(tmp, "\n");
	free(tmp);
	tmp = heredoc_str;
	heredoc_str = ft_strjoin(tmp, read_line);
	free(tmp);
	free(read_line);
	return (heredoc_str);
}

static int	fetch_heredoc_read_end(void)
{
	int	fd;

	fd = open(".heredoc.tmp", O_RDONLY, 0666);
	if (fd < 0)
		return (ERROR);
	if (unlink(".heredoc.tmp") == ERROR)
		return (ERROR);
	return (fd);
}

static void	pre_heredoc(t_node *node)
{
	char	*readline_str;
	char	*heredoc_str;

	heredoc_str = ft_strdup("");
	while (1)
	{
		readline_str = readline("> ");
		// if (!readline_str)
		// {
		// 	free(heredoc_str);
		// 	exit(EXIT_SUCCESS);
		// }
		if (ft_strcmp(readline_str, node->command[1]) == 0)
		{
			free(readline_str);
			break ;
		}
		heredoc_str = fetch_heredoc_str(heredoc_str, readline_str);
	}
	if (write_to_temp_file(heredoc_str) == ERROR)
	{
		free(heredoc_str);
		exit(EXIT_FAILURE);
	}
	free(heredoc_str);
	exit(EXIT_SUCCESS);
}

int	fetch_heredoc_fd(t_node *node)
{
	int		pid;

	pid = fork();
	if (pid == ERROR)
		return (ERROR);
	else if (pid == 0)
	{
		heredoc_signal_function();
		pre_heredoc(node);
	}
	waitpid(pid, &glob_status, 0);
	signals_function();
	if (WEXITSTATUS(glob_status) == ERR_ETC)
		return (ERROR);
	return (fetch_heredoc_read_end());
}
