/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoidptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:04:41 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/20 15:56:58 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putvoidptr(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		i += ft_putstr("0x0");
	else
	{
		i += ft_putstr("0x");
		i += ft_puthexadecimalnbr(((unsigned long long int)ptr), 0);
	}
	return (i);
}
