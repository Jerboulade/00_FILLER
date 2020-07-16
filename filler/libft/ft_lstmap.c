/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:08:29 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:28:27 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_cpy;
	t_list	*begin_list;

	if (!lst || !f)
		return (NULL);
	begin_list = f(lst);
	lst_cpy = begin_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst_cpy->next = ft_memalloc(sizeof(t_list))))
			return (NULL);
		if (!(lst_cpy->next = f(lst)))
			return (NULL);
		lst_cpy = lst_cpy->next;
	}
	return (begin_list);
}
