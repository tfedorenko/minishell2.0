/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:44:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/26 11:38:42 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*
** int main (void)
** {
** 	char big[] = "lorem ipsum dolor sit amet";
** 	char small[] = "dolor"**
** 	char *ptr = ft_strnstr (big, small, 15)**
** 	printf ("orig ->%s\n", ptr);
** 	printf ("lib -> %s\n", strnstr(big, small, 15));
** }
*/
