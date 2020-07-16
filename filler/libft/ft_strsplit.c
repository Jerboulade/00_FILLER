/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:08:15 by jecarere          #+#    #+#             */
/*   Updated: 2018/11/23 19:09:21 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**fill_tab(char **res, char *tmp, size_t nb_word)
{
	int		i;
	int		j;
	size_t	word_max;

	i = 0;
	j = 0;
	word_max = nb_word;
	while (nb_word > 0)
	{
		while (!tmp[i])
			i++;
		if (!(res[j] = ft_strsub(tmp, i, ft_strlen(tmp + i))))
		{
			ft_free_tab(res, word_max);
			return (NULL);
		}
		while (tmp[i])
			i++;
		j++;
		nb_word--;
	}
	res[j] = NULL;
	return (res);
}

static char		*transform_c(char *tmp, int i, char c)
{
	while (tmp[i])
	{
		if (tmp[i] == c)
			tmp[i] = 0;
		i++;
	}
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		nb_word;
	char		**res;
	char		*tmp;

	if (!s || !c)
		return (NULL);
	if (!(tmp = ft_strdup(s)))
		return (NULL);
	nb_word = ft_count_word(tmp, c);
	if (!(res = malloc(sizeof(*res) * (nb_word + 1))))
		return (NULL);
	tmp = transform_c(tmp, 0, c);
	res = fill_tab(res, tmp, nb_word);
	return (res);
}
