/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:16:59 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:48:05 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
			i++;
	}
	return (0);
}

/*
** int main (void)
** {
** 	const char str1[] = "Rwslan";
** 	const char str2[] = "Ruslan";

** 	int n = 3;

** 	int ptr = ft_strncmp(str1, str2, n)**
** 	if (ptr < 0)
** 	{
** 			printf ("str1 is less than str2");
** 	}
** 	else if(ptr > 0)
** 	{
** 		printf ("str1 is greater than s2");
** 	} else 
** }
** 	{
** 		printf ("they are finally equal");
** 	}
*/