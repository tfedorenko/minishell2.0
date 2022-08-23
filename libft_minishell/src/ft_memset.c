/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:20:03 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:57:59 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;
	size_t	i;

	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
** void printArray (char arr[], int n)
** {
** 	int i = 0;

** 	while (i < n)
** 	{
** 		printf ("%c", arr[i]);
** 		i++;
** 	}
** 	printf("\n");
** }

** int main (void)
** {
** 	char str1[SIZE_ARRAY] = "RuslanKubaev000000";
** 	char str2[SIZE_ARRAY] = "RuslanKubaev000000";

** 	printf("Before:\n");
** 	printArray(str1, SIZE_ARRAY);
** 	printArray(str2, SIZE_ARRAY);

** 	ft_memset(str1, '1', 12);
** 	ft_memset(str2, '1', 12);

** 	printf("After:\n");
** 	printArray(str1, SIZE_ARRAY);
** 	printArray(str2, SIZE_ARRAY);
** }
*/