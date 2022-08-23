/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:27:03 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:51:41 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	if (dstsize < dst_length + 1)
	{
		return (dstsize + src_length);
	}
	if (dstsize > dst_length)
	{
		while (src[i] != '\0' && dst_length + 1 + i < dstsize)
		{
			dst[dst_length + i] = src[i];
			i++;
		}
		if (i < dstsize)
			dst[dst_length + i] = '\0';
	}
	return (dst_length + src_length);
}
