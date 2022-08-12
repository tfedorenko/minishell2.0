/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:59:24 by tfedoren          #+#    #+#             */
/*   Updated: 2021/12/12 15:59:24 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*src;
	unsigned int	i;

	i = 0;
	src = (unsigned char *)arr;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return (&src[i]);
		i++;
	}
	return (0);
}
