/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:42:13 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/19 22:43:49 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	make_printable_values(const char conversion, va_list args)
{
	int	i;

	i = 0;
	if (conversion == 'c')
		i = i + ft_putchar(va_arg(args, int));
	else if (conversion == 's')
		i = i + ft_putstr(va_arg(args, char *));
	else if (conversion == 'd' || conversion == 'i')
		i = i + ft_putnbr(va_arg(args, int));
	else if (conversion == 'u')
		i = i + ft_unsigned_nbr(va_arg(args, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		i += ft_hexadecimal_nbr(va_arg (args, unsigned int), conversion);
	else if (conversion == 'p')
	{
		i = ft_putstr("0x");
		i = i + ft_pointer_nbr(va_arg(args, long unsigned int));
	}
	else if (conversion == '%')
		i = i + ft_putchar('%');
	else
		i = i + ft_putchar(conversion);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (i);
			count = count + make_printable_values(str[i], args);
		}
		else
			count = count + ft_putchar (str[i]);
		i++;
	}
	va_end (args);
	return (count);
}


// int main (void)
// {
// 	ft_printf ("%s\n", "ruslan");
// 	// printf ("%u\n", 456);
// }