/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:21:33 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/08 15:54:06 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	count;

	start = 0;
	count = 0;
	if (!s1 || !set)
		return (NULL);
	length = (ft_strlen(s1));
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
	{
		start++;
		count++;
	}
	while (length > 0 && ft_strchr(set, s1[length]))
	{
		length--;
		count++;
	}
	length = ft_strlen(s1) - count;
	return (ft_substr(s1, start, length + 1));
}

// int main (void)
// {
// 	 char str1[] = "heymanhowallof";
// 	 char set[] = "fheyo";
// //   strcpy(dst, dst + 2, )
// 	// char *ptr[] = ft_strtrim(str1, set);

// 	// int num = ft_strlen(ft_strtrim(str1, set));

// 	printf("string ---> %s\n", ft_strtrim(str1, set));
// 	// printf("integer ---> %d\n", num);
// }
