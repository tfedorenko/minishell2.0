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

int	open_temp_file(void)
{
	int		fd;
	int		nb;
	char	*tmp_file;
	char	*nb_str;

	nb = 1;
	tmp_file = ft_strdup(".tmp");
	fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
	while (fd == ERROR)
	{
		free(tmp_file);
		nb_str = ft_itoa(nb);
		tmp_file = ft_strjoin(".tmp", nb_str);
		free(nb_str);
		fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
		nb++;
	}
	temp_files(tmp_file, ADD);
	return (fd);
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

int	fetch_heredoc_read_end(int temp_fd, char *heredoc_str)
{
	int		fd;
	char	*temp_file;

	temp_file = temp_files(NULL, GET)->value;
	write(temp_fd, heredoc_str, ft_strlen(heredoc_str));
	close(temp_fd);
	fd = open(temp_file, O_RDONLY);
	free(heredoc_str);
	if (glob_status == ERR_ETC)
	{
		temp_files(NULL, DEL);
		close(fd);
		return (ERROR);
	}
	return (fd);
}

static void	pre_heredoc(char *readline_str, char *heredoc_str, t_node *node)
{
	int		fd;
	char	*heredoc_str;
	char	*readline_str;

	heredoc_str = ft_strdup("");
	glob_status = 0;
	fd = open_temp_file();

	while (1)
	{
		readline_str = readline("> ");
		if (!readline_str)
			exit(1);
		if (ft_strcmp(readline_str, node->command[1]) == 0)
		{
			free(readline_str);
			exit(1);
		}
		heredoc_str = fetch_heredoc_str(heredoc_str, readline_str);
	}
}

int	fetch_heredoc_fd(t_node *node)
{
	int		fd;
	char	*heredoc_str;
	char	*readline_str;
	int		pid;

	heredoc_str = ft_strdup("");
	readline_str = NULL;
	glob_status = 0;
	fd = open_temp_file();
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		heredoc_signal_function();
		pre_heredoc(readline_str, heredoc_str, node);
	}
	waitpid(pid, &glob_status, 0);
	signals_function();
	return (fetch_heredoc_read_end(fd, heredoc_str));
}
