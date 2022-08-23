/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:55:37 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 15:04:18 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
	{
		len = ft_strlen(s);
	}
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		return (NULL);
	}
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
int main ()
{
	char st1[] = "rf";
 	int c = ft_substr(st1, 1, 1);

	char *str = "ruslanhello";
	char *nb = ft_substr(str, 4, 5);

	printf("---> %s\n", nb);
}
*/