/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:03:46 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:12:28 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_algo_filler10(t_enf3 *k, int tab[3000][2])
{
	if (5 * tab[k->j][0] + tab[k->j][1] > k->q22)
	{
		k->q22 = 5 * tab[k->j][0] + tab[k->j][1];
		k->i3 = k->j;
	}
}

void		ft_algo_filler5(t_enf3 *k, int tab[3000][2])
{
	if (k->q > k->w)
	{
		if (k->q >= 0 && k->w >= 0)
			ft_algo_filler10(k, tab);
		else
			ft_algo_filler7(k, tab);
	}
	else
	{
		if (k->q >= 0 && k->w >= 0)
		{
			if (tab[k->j][0] + tab[k->j][1] * 5 > k->q22)
			{
				k->q22 = tab[k->j][0] + tab[k->j][1] * 5;
				k->i3 = k->j;
			}
		}
		else
			ft_algo_filler8(k, tab);
	}
	k->j++;
}

void		ft_algooo(t_enf *e, t_enf3 *k, int tab[3000][2])
{
	if (k->j == 0)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
	else if (k->zz > 0)
	{
		ft_putnbr(k->i4 - e->y_min8);
		ft_putchar(' ');
		ft_putnbr(k->i5 - e->x_min8);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(tab[k->i3][0] - e->y_min8);
		ft_putchar(' ');
		ft_putnbr(tab[k->i3][1] - e->x_min8);
		ft_putchar('\n');
	}
	free(k);
}

void		ft_algo_filler(t_enf *e)
{
	int		tab[3000][2];
	t_enf3	*k;

	k = (t_enf3 *)malloc(sizeof(t_enf3));
	ft_algo_filler2(e, -1, k, tab);
	k->j = 0;
	k->q22 = 0;
	k->w22 = 0;
	k->i3 = 0;
	e->max_y = (e->max_y + e->min_y) / 2;
	e->max_x = (e->max_x + e->min_x) / 2;
	e->max_y2 = (e->max_y2 + e->min_y2) / 2;
	e->max_x2 = (e->max_x2 + e->min_x2) / 2;
	k->q = e->max_y - e->max_y2;
	k->w = e->max_x - e->max_x2;
	while (tab[k->j][0] != -1)
		ft_algo_filler5(k, tab);
	ft_algooo(e, k, tab);
}
