/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:14:28 by jecarere          #+#    #+#             */
/*   Updated: 2018/11/20 12:14:36 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_word(char *str, char c)
{
	size_t		on_word;
	size_t		on_c;
	size_t		nb_word;
	int			i;

	if (!str || !c)
		return (0);
	on_word = 0;
	on_c = 1;
	nb_word = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != c && on_word == 0 && ++nb_word)
		{
			on_word = 1;
			on_c = 0;
		}
		if (str[i] == c && on_c == 0)
		{
			on_word = 0;
			on_c = 1;
		}
	}
	return (nb_word);
}
