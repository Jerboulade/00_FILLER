/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:14:10 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:26:01 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(s2 = ft_strnew(i)))
		return (NULL);
	while (i--)
		s2[i] = f((char)s[i]);
	return (s2);
}
