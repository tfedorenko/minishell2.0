/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:31:26 by tfedoren          #+#    #+#             */
/*   Updated: 2022/04/27 20:31:26 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	while (s2[j] && s2[j] != '\n')
		j++;
	if (s2[j] && s2[j] == '\n')
		j++;
	str = (char *)malloc(sizeof(char) *(ft_strlen(s1) + j + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] && s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*ft_strchr_gnl(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

void	*ft_memmove_gnl(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst || !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (d == s)
		return (d);
	if (s < d)
	{
		i = n;
		while (i--)
			((char *)d)[i] = ((char *)s)[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			((char *)d)[i] = ((char *)s)[i];
	}
	return (d);
}
