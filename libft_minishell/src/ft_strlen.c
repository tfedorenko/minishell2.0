/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:33:55 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:49:16 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
** int main ()
** {
** 	char str[20] = "Ruslan";
** 	int value = ft_strlen(str);
** 	printf ("the length is %i\n", value);
** }

** int main(int argc, char *argv[])
** {
** 	if(argc < 2)
** 	{
** 		return 1;
** 	}

** 	else
** 	{
** 		int i = 1;
** 		int result = ft_strlen(argv[i]);
** 		printf("The length of the string: %d", result);

**	}
** }
*/