/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:08:09 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:08:17 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	if (!(new_link = (t_list *)malloc(sizeof(*new_link))))
		return (NULL);
	new_link->next = NULL;
	if (!content)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		if (!(new_link->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	return (new_link);
}
