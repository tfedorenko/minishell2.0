/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:01:17 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/06 16:14:05 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_length;

	s_length = ft_strlen(s);
	if (s)
	{
		while (s_length >= 0)
		{
			if (s[s_length] == (char)c)
			{
				return ((char *)&s[s_length]);
			}
			s_length--;
		}
		if ((char)c == '\0')
			return ((char *)s + s_length);
	}
	return (0);
}

/*
** the strrchr finds the last occurrence of
** c(converted to a char) in the string pointed to by s

** There is a difference between "a string", 
** "an array of characters" and "a char* pointer".

** A C String is a number of characters terminated by a null character.
** An array of characters is a defined number of characters.

** A char* pointer is technically a pointer to a single character,
**  but often used to mark a point in a C style string.

** int ft_strlen (const char *s)
**	{
** 		int i = 0;
**		while (s[i] != '\0')
** 		{
** 			i++;
** 		}
** 		return i;
** 	}

** int main (void)
** {
** 	char str[30] = "This is the length of a string";

** 	char value = 'i';

**	char *ptr = ft_strrchr(str, value);

** 	printf ("Character %c is found at the position--->%ld\n",value,ptr-str+1);
** 	printf ("Last occurrence of character %c is in ---> %s\n", value, ptr);
** }
*/