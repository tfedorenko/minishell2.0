/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:15:14 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:07:50 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length_calculation(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != '\0')
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*copy_string(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dst[i] = '\0';
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	long int	i;
	char		*ptr;

	i = length_calculation(n);
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	if (n == -2147483648)
		return (copy_string(ptr, "-2147483648"));
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * (-1);
	}
	ptr[i] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n != '\0' && i-- > 0)
	{
		ptr[i] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
