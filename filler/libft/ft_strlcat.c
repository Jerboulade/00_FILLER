/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:42:47 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:30:12 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_size;
	size_t i;

	i = 0;
	dst_size = ft_strlen(dst);
	if (dst_size >= size)
		return (size + ft_strlen(src));
	while (*src && (dst_size < size - 1))
	{
		dst[dst_size++] = *src++;
		i++;
	}
	dst[dst_size] = 0;
	return (ft_strlen(src) + ft_strlen(dst));
}
