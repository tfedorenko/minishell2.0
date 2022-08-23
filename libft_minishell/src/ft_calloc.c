/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:57 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:09:32 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
