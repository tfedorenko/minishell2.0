/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:33:45 by tfedoren          #+#    #+#             */
/*   Updated: 2021/12/02 18:33:45 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	size_t	i;
	char	*d;

	d = dst;
	i = 0;
	while (i < len)
	{
		d[i] = c;
		i++;
	}
	return (dst);
}
