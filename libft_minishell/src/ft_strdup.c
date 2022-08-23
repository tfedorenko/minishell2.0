/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:59:20 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:53:20 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*str;
	int		i;

	length = ft_strlen(s1);
	i = 0;
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	while (i < length)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
