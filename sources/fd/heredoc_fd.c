/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:22:51 by rkultaev          #+#    #+#             */
/*   Updated: 2022/09/02 18:35:33 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	glob_status;

int	open_temp_file(void)
{
	int		fd;
	int		nb;
	char	*tmp_file;
	char	*nb_str;

	nb = 1;
	tmp_file = ft_strdup(".tmp");
	fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL);
	while (fd == ERROR)
	{
		free(tmp_file);
		nb_str = ft_itoa(nb);
		tmp_file = ft_strjoin(".tmp", nb_str);
		free(nb_str);
		fd = open(tmp_file, O_WRONLY | O_CREAT | O_EXCL);
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

int	fetch_heredoc_fd(t_node *node)
{
	int		fd;
	char	*heredoc_str;
	char	*readline_str;

	heredoc_str = ft_strdup("");
	glob_status = 0;
	fd = open_temp_file();
	while (1)
	{
		readline_str = readline("heredoc> ");
		if (!readline_str)
			break ;
		if (ft_strcmp(readline_str, node->command[1]) == 0)
		{
			free(readline_str);
			break ;
		}
		heredoc_str = fetch_heredoc_str(heredoc_str, readline_str);
	}
	return (fetch_heredoc_read_end(fd, heredoc_str));
}
