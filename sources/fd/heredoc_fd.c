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

int write_to_temp_file(char *heredoc_str)
{
	int		fd;
	// int		nb;
	// char	*tmp_file;
	// char	*nb_str;

	// nb = 1;
	// tmp_file = ft_strdup(".tmp");
	fd = open(".heredoc.tmp", O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd == ERROR)
		return (ERROR);
	// printf("hererdoc str: %s\n", heredoc_str);
	write(fd, heredoc_str, ft_strlen(heredoc_str));
	close(fd);
	// while (fd == ERROR)
	// {
	// 	free(tmp_file);
	// 	nb_str = ft_itoa(nb);
	// 	tmp_file = ft_strjoin(".tmp", nb_str);
	// 	free(nb_str);
	// 	fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
	// 	nb++;
	// }
	// temp_files(tmp_file, ADD);
	return (SUCCESS);
}

// int	open_temp_file(void)
// {
// 	int		fd;
// 	int		nb;
// 	char	*tmp_file;
// 	char	*nb_str;

// 	nb = 1;
// 	tmp_file = ft_strdup(".tmp");
// 	fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
// 	while (fd == ERROR)
// 	{
// 		free(tmp_file);
// 		nb_str = ft_itoa(nb);
// 		tmp_file = ft_strjoin(".tmp", nb_str);
// 		free(nb_str);
// 		fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
// 		nb++;
// 	}
// 	temp_files(tmp_file, ADD);
// 	return (fd);
// }

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

static int fetch_heredoc_read_end(void)
// int	fetch_heredoc_read_end(int temp_fd, char *heredoc_str)
{
	int fd;

	fd = open(".heredoc.tmp", O_RDONLY, 0666);
	if (fd < 0)
		return (ERROR);
	if (unlink(".heredoc.tmp") == ERROR)
		return (ERROR);

	// char	*temp_file;

	// temp_file = temp_files(NULL, GET)->value;
	// write(temp_fd, heredoc_str, ft_strlen(heredoc_str));
	// printf("*******%d*******\n", temp_fd);
	// close(temp_fd);
	// printf("*******%d*******\n", temp_fd);
	// fd = open(temp_file, O_RDONLY, 0666);
	// free(heredoc_str);
	// printf("heeeeeeeeeey\n");
	// if (glob_status == ERR_ETC)
	// {
	// temp_files(NULL, DEL);
	// 	fprintf(stderr, "%d\n", fd);
	// 	close(fd);
	// 	fprintf(stderr, "%d\n", fd);
	// 	return (ERROR);
	// }
	return (fd);
}

// static int heredoc_free(char *readline_str, char *heredoc_str)
// {
// 	free(readline_str);
// 	free(heredoc_str);
// 	temp_files(NULL, DEL);
// 	return (0);
// }

static void pre_heredoc(t_node *node)
// static int	pre_heredoc(char *readline_str, char **heredoc_str, t_node *node)
{
	char *readline_str;
	char *heredoc_str;
	// glob_status = 0;

	heredoc_str = ft_strdup("");
	while (1)
	{
		readline_str = readline("> ");
		if (!readline_str)
		{
			free(heredoc_str);
			exit(EXIT_SUCCESS);
		}
		// if (glob_status == ERR_ETC)
		// {
		// 	// printf("here\n");
		// 	return (heredoc_free(readline_str, *heredoc_str));
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
	// int		fd;
	// char	*heredoc_str;
	// char	*readline_str;
	int		pid;

	// heredoc_str = ft_strdup("");
	// readline_str = NULL;

	// fd = open_temp_file();
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
