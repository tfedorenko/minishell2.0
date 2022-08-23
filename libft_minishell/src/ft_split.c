/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:03:46 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/26 17:44:28 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *str, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] && str[i] == c)
			{
				i++;
			}
		}
		else
		{
			while (str[i] && str[i] != c)
			{
				i++;
			}
			num++;
		}
	}
	return (num);
}

static char	**ft_set_place(char **str, char const *s1, char ch, int wordcount)
{
	int	i;
	int	length;
	int	word;

	word = 0;
	i = 0;
	length = 0;
	while (s1[i] && word < wordcount)
	{
		while (s1[i] != '\0' && s1[i] == ch)
		{
			i++;
		}
		while (s1[i] != '\0' && s1[i] != ch)
		{
			i++;
			length++;
		}
	str[word] = ft_substr(s1, i - length, length);
	length = 0;
	word++;
	}
	str[word] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s)
	{
		return (NULL);
	}
	i = count_words(s, c);
	ptr = malloc(sizeof(char *) * (i + 1));
	if (!ptr)
	{
		return (NULL);
	}
	ft_set_place(ptr, s, c, i);
	return (ptr);
}

/*
** n --> // gathers occurences of character and increments the amount and
**returns the number of split words

**length ---> counts the length
** of each substring by subtracting the general counter 'i' and 'length'

**word ---> counts words after every char delimiter in the string 
** int main (void)
** {
** 	char str1[] = "howareyoudoingman";
** 	char c = 'a';
** 	char **ptr = ft_split(str1, c);

** 	int i = 0;
** 	while (ptr[i])
** 	{
** 		printf ("%s\n", ptr[i]);
** }
** 		printf ("%zu\n", strlen(*ft_split(str1, c)));
** 		i++;
** 	}
*/