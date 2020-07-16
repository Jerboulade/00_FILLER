/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:18:19 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/23 10:18:25 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *tmp_s1;
	unsigned char *tmp_s2;

	if (!n)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (--n && (*tmp_s1 == *tmp_s2))
	{
		tmp_s1++;
		tmp_s2++;
	}
	return (*tmp_s1 - *tmp_s2);
}
