/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:00:38 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:32:59 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && (len >= needle_len))
	{
		if (*haystack == *needle)
		{
			if (!(ft_strncmp(haystack, needle, needle_len)))
				return (char *)(haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
