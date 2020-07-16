/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:23:02 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 22:32:17 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					neg;
	int					i;

	nb = 0;
	neg = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') \
	|| (str[i] == '\n') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (nb > 9223372036854775807)
		return ((neg == 1) ? 0 : -1);
	if (neg == 1)
		return (-nb);
	return ((int)nb);
}
