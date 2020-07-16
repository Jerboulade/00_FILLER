/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:15:34 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:31:46 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			tmp = s;
		s++;
	}
	if (*s == (char)c)
		tmp = s;
	return ((char *)tmp);
}
