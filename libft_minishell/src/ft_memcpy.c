/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:58:15 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:00:13 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1;
	size_t				i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst1 == NULL && src1 == NULL)
		return (NULL);
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
