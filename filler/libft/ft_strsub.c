/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:28:37 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:33:24 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(new, s, len);
	new[len] = 0;
	return (new);
}
