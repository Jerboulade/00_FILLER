/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:21:47 by jecarere          #+#    #+#             */
/*   Updated: 2018/11/23 19:06:04 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = ft_strlen(s1);
	if (!(cpy = (char *)malloc(sizeof(*cpy) * (i + 1))))
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
