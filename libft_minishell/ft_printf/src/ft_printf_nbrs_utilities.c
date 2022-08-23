/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs_utilities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/19 15:59:06 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (write (1, "-2147483648", 11));
	}
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = (-n);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		count += ft_putchar(n + 48);
	}
	return (count);
}

int	ft_unsigned_nbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i = i + (ft_unsigned_nbr(n / 10));
		i = i + (ft_unsigned_nbr(n % 10));
	}
	else
	{
		i = i + (ft_putchar(n + 48));
	}
	return (i);
}

int	ft_hexadecimal_nbr(unsigned int n, const char value)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_hexadecimal_nbr(n / 16, value);
		count = count + ft_hexadecimal_nbr(n % 16, value);
	}
	else
	{
		if (n < 10)
		{
			count = count + ft_putchar (n + 48);
		}
		else if (value == 'x')
		{
			count = count + ft_putchar (n + 97 - 10);
		}
		else if (value == 'X')
		{
			count = count + ft_putchar (n + 65 - 10);
		}
	}
	return (count);
}

int	ft_pointer_nbr(unsigned long int n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		count = count + ft_putchar(n + 48);
	}
	else if (n < 16)
	{
		count = count + ft_putchar(n + 97 - 10);
	}
	else
	{
		count = count + ft_pointer_nbr(n / 16);
		count = count + ft_pointer_nbr(n % 16);
	}
	return (count);
}
