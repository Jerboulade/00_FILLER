/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:22:40 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:16:45 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			return (++dst);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (NULL);
}
