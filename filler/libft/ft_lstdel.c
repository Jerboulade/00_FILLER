/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:07:13 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:07:22 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_current;
	t_list	*tmp_next;

	if (!alst || !del)
		return ;
	tmp_current = *alst;
	while (tmp_current)
	{
		tmp_next = tmp_current->next;
		ft_lstdelone(&tmp_current, del);
		tmp_current = tmp_next;
	}
	*alst = NULL;
}
