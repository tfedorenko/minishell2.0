/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimalnbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:46:33 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/20 15:57:16 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexadecimalnbrlen(unsigned long long int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static void	ft_hexadecimalnbr_format(unsigned int n, int format)
{
	if (format == 0)
		ft_putchar('a' + n - 10);
	if (format == 1)
		ft_putchar('A' + n - 10);
}

int	ft_puthexadecimalnbr(unsigned long long int n, int format)
{
	unsigned int	i;

	i = ft_hexadecimalnbrlen(n);
	if (n == 0)
		ft_putchar('0');
	else if (n >= 16)
	{
		ft_puthexadecimalnbr(n / 16, format);
		ft_puthexadecimalnbr(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_hexadecimalnbr_format(n, format);
	}
	return (i);
}
