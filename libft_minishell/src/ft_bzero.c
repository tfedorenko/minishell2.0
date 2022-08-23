/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:44:11 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:10:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
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
** 	char str1[SIZE_ARRAY] = "RuslanKubaevkkkkkk";
** 	char str2[SIZE_ARRAY] = "RuslanKubaev000000";

** 	printf("Before:\n");
** 	printArray(str1, SIZE_ARRAY);
** 	printArray(str2, SIZE_ARRAY);

** 	ft_bzero(str1, 12);
** 	ft_bzero(str2, 12);

** 	printf("After:\n");
** 	printArray(str1, SIZE_ARRAY);
** 	printArray(str2, SIZE_ARRAY);
** }
*/