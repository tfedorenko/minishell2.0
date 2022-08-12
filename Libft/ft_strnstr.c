/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:03:47 by tfedoren          #+#    #+#             */
/*   Updated: 2021/12/12 20:03:47 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{		
		j = 0;
			while (little[j] && j + i < len)
			{
				if (big[i + j] != little[j])
					break ;
				j++;
			}
			if (little[j] == 0)
				return ((char *)(big + i));
		}
	i++;
	}
	return (NULL);
}
