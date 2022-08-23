/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:48:29 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:50:08 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
	{
		return (ft_strlen(src));
	}
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	{
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (ft_strlen(src));
}

/*
** int main (void)
** {
** 	const char src1[10] = "1234567890";
** 	char dst1[10] = "0987654321";

** 	ft_strlcpy(dst1, src1, 6);

** 	printf("destination source is --> %s\n", dst1);
** }
*/