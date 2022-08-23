/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:13:50 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/16 17:06:43 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*before_new_line(char *bucket)
{
	int		i;

	i = 0;
	if (!bucket)
	{
		return (0);
	}
	while (bucket[i] != '\0' && bucket[i] != '\n')
	{
		i++;
	}
	return (ft_substr(bucket, 0, i + 1));
}

static char	*after_new_line(char *bucket)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (!bucket)
		return (NULL);
	while (bucket[i])
	{
		if (bucket[i] == '\n')
		{
			if (ft_strlen(bucket) - i - 1 == 0)
			{
				free(bucket);
				return (NULL);
			}
			str = (ft_substr(bucket, i + 1, (ft_strlen(bucket) - i)));
			free(bucket);
			return (str);
		}
		i++;
	}
	free(bucket);
	return (NULL);
}

char	*handling_static_with_temp(char *ptr_buffer, char *static_buff)
{
	char	*tmp;

	tmp = ft_strjoin(static_buff, ptr_buffer);
	free (static_buff);
	static_buff = tmp;
	return (tmp);
}

static char	*read_data(char *static_buff, int fd)
{
	char	*ptr_buffer;
	int		read_outcome;

	read_outcome = 1;
	ptr_buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while ((ft_strchr(static_buff, '\n') == NULL) && read_outcome != 0)
	{
	read_outcome = read(fd, ptr_buffer, BUFFER_SIZE);
		if (read_outcome < 1 && !static_buff)
		{
			free (ptr_buffer);
			return (NULL);
		}
	ptr_buffer[read_outcome] = '\0';
		if (static_buff)
			static_buff = handling_static_with_temp(ptr_buffer, static_buff);
		else
			static_buff = ft_strjoin("", ptr_buffer);
	}
	free(ptr_buffer);
	return (static_buff);
}

char	*get_next_line(int fd)
{
	char		*line_output;
	static char	*bucket;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	bucket = read_data(bucket, fd);
	if (!bucket)
	{
		free(bucket);
		return (NULL);
	}
	line_output = before_new_line(bucket);
	bucket = after_new_line(bucket);
	return (line_output);
}




int main ()
{
	int fd_pointer = open ("/Users/rkultaev/42_Wolfsburg/get_next_line/get_next_line_project/get_next_line/tests/42_with_nl", O_RDONLY);
	char *line;
	
	line = get_next_line(fd_pointer);
	// printf ("%s", line);
	// printf("%s", line);
	// if (line)
	// 	free(line);
	// line = get_next_line(fd_pointer);
	// printf("%s", line);
	// if (line)
	// 	free(line);
	while (line)
	{
		printf("%s", line);
		
		free(line);
		line = get_next_line(fd_pointer);
		
		// line = get_next_line(fd_pointer);
		// printf("str: %s", line);
		
	}
	
	close(fd_pointer);
	return (0);
}
