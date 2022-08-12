/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:31:35 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/23 18:44:46 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
