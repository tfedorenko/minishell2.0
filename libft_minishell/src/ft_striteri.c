/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:01:39 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:52:50 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		length;

	i = 0;
	if (!s)
		return ;
	length = ft_strlen(s);
	while (i < length)
	{
		f(i, s + i);
		i++;
	}
}
