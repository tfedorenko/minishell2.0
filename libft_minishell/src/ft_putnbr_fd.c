/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:01:02 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:57:02 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = (-n);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		str = n % 10 + 48;
		write (fd, &str, 1);
	}
	else
	{
		str = n + 48;
		write (fd, &str, 1);
	}
}
