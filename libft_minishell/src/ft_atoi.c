/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:52:59 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/26 11:35:35 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	long				conversion;
	long				i;
	long long int		value;

	value = 0;
	conversion = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			conversion = -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && (str[i] != '\0'))
	{
		value = (value * 10) + str[i] - 48;
		i++;
	}
	return (value * conversion);
}
