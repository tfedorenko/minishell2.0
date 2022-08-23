/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:42:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/26 11:38:52 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del))
{
	t_list	*new;
	t_list	*value;

	if (!lst || !f)
		return (NULL);
new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
value = new;
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&value, del);
			return (value);
		}
		ft_lstadd_back(&value, new);
			new = new -> next;
	}
	return (value);
}
