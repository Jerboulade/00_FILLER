/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:18:20 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:35:28 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s)
		return (NULL);
	len = (int)ft_strlen(s) - 1;
	if (((s[0] != ' ') && (s[0] != '\n') && (s[0] != '\t')) \
	&& ((s[len] != ' ') && (s[len] != '\n') && (s[len] != '\t')))
	{
		if (!(new = ft_strdup(s)))
			return (NULL);
		return (new);
	}
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len > i)
		len--;
	if (!(new = ft_strsub(s, i, (len - i + 1))))
		return (NULL);
	return (new);
}
