/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:03:57 by tfedoren          #+#    #+#             */
/*   Updated: 2021/12/17 16:03:57 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a string 
representing the integer received as an argument.
Negative numbers must be handled.
Return value. The string representing the integer. 
NULL if the allocation fails.*/

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n1;
	int		len;

	n1 = n;
	len = ft_n_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	str[len--] = '\0';
	if (n1 == 0)
		str[0] = '0';
	if (n1 < 0)
	{
		str[0] = '-';
		n1 = n1 * (-1);
	}
	while (n1 > 0)
	{
		str[len--] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	return (str);
}
