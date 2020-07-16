/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:20:02 by jecarere          #+#    #+#             */
/*   Updated: 2018/10/30 20:32:28 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_neg(int len, int n2, char *res)
{
	res[0] = '-';
	n2 *= -1;
	len += 1;
	res[len] = 0;
	while (--len)
	{
		res[len] = (n2 % 10) + '0';
		n2 /= 10;
	}
	return (res);
}

static char	*is_pos(int len, int n2, char *res)
{
	res[len] = 0;
	while (len--)
	{
		res[len] = (n2 % 10) + '0';
		n2 /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		n2;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 2147483647)
		return (ft_strdup("2147483647"));
	len = 1;
	neg = 1;
	n2 = n;
	if (n < 0)
		neg = 2;
	while ((n /= 10) != 0)
		len++;
	if (!(res = malloc(sizeof(*res) * (len + neg))))
		return (NULL);
	if (neg == 2)
		return (is_neg(len, n2, res));
	else
		return (is_pos(len, n2, res));
}
