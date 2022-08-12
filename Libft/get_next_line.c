/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:25:43 by tfedoren          #+#    #+#             */
/*   Updated: 2022/07/25 18:46:29 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buff_after_line(char *buff)
{
	int			rest_buff;

	rest_buff = ft_strlen_gnl(buff) - ft_strlen_gnl(ft_strchr(buff, '\n') + 1);
	ft_memmove_gnl(buff, &buff[rest_buff], \
		ft_strlen_gnl(ft_strchr(buff, '\n') + 1));
	buff[ft_strlen_gnl(buff) - rest_buff] = '\0';
}

char	*create_last(char *buff, char *line)
{
	line = ft_strjoin_gnl(line, buff);
	buff[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			count;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	while (!ft_strchr_gnl(buff, '\n'))
	{
		if (*buff)
			line = ft_strjoin_gnl(line, buff);
		count = read(fd, buff, BUFFER_SIZE);
		if (count <= 0 && (!*line))
		{
			free(line);
			return (NULL);
		}
		buff[count] = '\0';
		if (!ft_strchr_gnl(buff, '\n') && count < BUFFER_SIZE)
			return (create_last(buff, line));
	}
	line = ft_strjoin_gnl(line, buff);
	buff_after_line(buff);
	return (line);
}
