/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:50:53 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:26:35 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = 0;
	i = ft_strlen(s);
	if (!(s2 = ft_strnew(i)))
		return (NULL);
	while (j < i)
	{
		s2[j] = f(j, (char)s[j]);
		j++;
	}
	return (s2);
}
