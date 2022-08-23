/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:58:32 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 00:59:50 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	i;

	dst1 = (char *) dst;
	src1 = (char *) src;
	i = 0;
	if (src1 > dst1)
	{
		while (i < len)
		{
		dst1[i] = src1[i];
		i++;
		}
		return (dst1);
	}
	else if (src1 < dst1)
	{
		while (len > 0)
		{
		dst1[len - 1] = src1[len - 1];
		len--;
		}
	}
	return (dst1);
}

/*
** int main(int argc, char* argv[])
** {
**   char str1[30] = "Tresor";
**   char str2[30] = "Ruslankkkkk";
**
**   printf("\n");
**   printf("After memmove()\n");
**
**   printf("ft_memmove is -----> %s\n", ft_memmove(str1 + 5, str2 + 3, 5));
**
** printf("After memcpy()\n");
**   printf("memcpy is -----> %s", memcpy(str1 + 5, str2 + 3, 5));
**
** }
**	 void	print_elements(char *array, int size)
** {
**   int i;
**   printf ("Elements : ");
**   for (i = 0; i < size; i++) {
**     printf ("%c, ", array[i]);
**   }
** ** }
*/