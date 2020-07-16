/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:15:26 by jecarere          #+#    #+#             */
/*   Updated: 2018/11/20 12:15:29 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, size_t nb_tab)
{
	size_t i;

	if (!*tab || !tab)
		return ;
	i = 0;
	while (i < nb_tab)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
