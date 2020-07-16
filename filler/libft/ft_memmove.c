/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:30:43 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:15:10 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp_dst;
	unsigned char *tmp_src;

	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	if (dst > src)
	{
		while (len--)
			tmp_dst[len] = tmp_src[len];
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
