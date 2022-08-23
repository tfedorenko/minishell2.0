/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:46:59 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/08 16:14:40 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		length;
	char		*ptr;

	i = 0;
	if (!s || !f)
	{
		return (NULL);
	}
	length = ft_strlen(s);
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	while (i < length)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
