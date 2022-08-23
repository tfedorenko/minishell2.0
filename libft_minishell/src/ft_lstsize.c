/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:41:43 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:02:14 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
** int main()
** {
** 	t_list *ptr;
** 	t_list *ptr2;
** 	ptr = malloc(sizeof(t_list));
** 	ptr2 = malloc(sizeof(t_list));
** 	t_list *head;

** 	head = ptr;
** 	ptr->content = (int *)4;
** 	ptr->next = ptr2;
** 	ptr2->content = (int *)5;
** 	ptr2->next = NULL;

** 	int i;
** 	i = ft_lstsize(head);
** 	printf("%d", i);

** 	printf("%d %d\n", (int)ptr->content, (int *)content);
** }
*/