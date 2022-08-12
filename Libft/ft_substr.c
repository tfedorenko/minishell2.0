/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:49:43 by tfedoren          #+#    #+#             */
/*   Updated: 2021/12/17 14:49:43 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Allocates (with malloc(3)) and returns a substring from the string ’s’.
//The substring begins at index ’start’ and is of maximum size ’len’.
// Return value The substring. NULL if the allocation fails.

//#1. The string from which to create the substring.
//#2. The start index of the substring in the string ’s’.
//#3. The maximum length of the substring.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	l = ft_strlen(s + start);
	if (l < len)
		len = l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
