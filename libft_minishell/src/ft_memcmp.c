/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:44:50 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:00:50 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*
** int main (void)
** {
** 	char str1[20] = "atoms\0\0\0\0";
** 	char str2[20] = "atoms\0abc";

** 	int n = 15;

** 	int ptr = ft_memcmp(str1, str2, n);

** 	if (ptr < 0)
** 	{
** 			printf ("str1 is less than str2");
** 	}
** 	else if(ptr > 0)
** 	{
** 		printf ("str1 is greater than s2");
** 	} else 
** 	{
** 		printf ("they are finally equal");
** 	}
** }
*/