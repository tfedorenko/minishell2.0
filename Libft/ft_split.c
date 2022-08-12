/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:16:23 by tfedoren          #+#    #+#             */
/*   Updated: 2021/12/19 21:16:23 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.
Return value. The array of new strings resulting from the split.
NULL if the allocation fails.*/

static int	ft_nmbr_of_str(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (j);
}

static char	*ft_str(const char *str, char c)
{
	int		i;
	char	*newstr;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static void	ft_free_str(int i, char **ptr)
{
	while (i < 0)
	{
		free (ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**p_str;
	int		nmbr_of_str;
	int		i;

	if (!s)
		return (NULL);
	nmbr_of_str = ft_nmbr_of_str(s, c);
	p_str = malloc(sizeof(char *) * (nmbr_of_str + 1));
	if (p_str == NULL)
		return (NULL);
	i = 0;
	while (i < nmbr_of_str)
	{
		while (*s && *s == c)
			s++;
		p_str[i] = ft_str(s, c);
		if (p_str[i] == NULL)
			ft_free_str(i, p_str);
		while (*s && *s != c)
			s++;
		i++;
	}
	p_str[i] = NULL;
	return (p_str);
}
