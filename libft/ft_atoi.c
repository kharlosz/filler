/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:03:08 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 02:24:18 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi2(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		i++;
		i = -i;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int i;
	int j;
	int k;
	int x;
	int l;

	j = 1;
	k = 0;
	x = 1;
	i = ft_atoi2(str);
	if (i < 0)
	{
		i = -i;
		x = -1;
	}
	l = i;
	while (str[i] > 47 && str[i] < 58)
		i++;
	while (i > l)
	{
		k = k + (str[i - 1] - 48) * j;
		i--;
		j *= 10;
	}
	return (x * k);
}
