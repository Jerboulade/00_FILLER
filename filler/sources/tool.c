/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:48:57 by jecarere          #+#    #+#             */
/*   Updated: 2020/03/11 17:55:40 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		*ft_intab(size_t size)
{
	int		*intab;
	size_t	i;

	i = -1;
	if (!size)
		return (NULL);
	if (!(intab = (int *)malloc(sizeof(*intab) * (size + 1))))
		return (NULL);
	while (++i < size)
		intab[i] = 0;
	intab[i] = -1;
	return (intab);
}

void	ft_intdel(int **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

void	ft_frintab(int **tab, int size)
{
	int i;

	i = -1;
	if (!tab)
		return ;
	while (++i < size)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}
