/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_filler2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:39:59 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:12:44 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_algo_filler3(t_enf3 *k, int y, int x)
{
	k->i4 = y;
	k->i5 = x;
	k->zzz = k->j;
	k->zz = k->z;
}

void		ft_algo_filler2(t_enf *e, int y, t_enf3 *k, int tab[3000][2])
{
	int		x;

	k->j = 0;
	k->zz = 0;
	k->zzz = 0;
	while (++y - e->y_min8 < e->board_y - 1)
	{
		x = -1;
		while (++x - e->x_min8 < e->board_x)
		{
			k->z = 0;
			if (ft_check_pos(e, y - e->y_min8, x - e->x_min8, &k->z) == 1)
			{
				tab[k->j][0] = y;
				tab[k->j][1] = x;
				if (k->z > k->zz)
					ft_algo_filler3(k, y, x);
				k->j++;
			}
		}
	}
	tab[k->j][0] = -1;
}

void		ft_algo_filler7(t_enf3 *k, int tab[3000][2])
{
	if (k->q < 0 && k->w >= 0)
	{
		if (-5 * tab[k->j][0] + tab[k->j][1] > k->q22)
		{
			k->q22 = -5 * tab[k->j][0] + tab[k->j][1];
			k->i3 = k->j;
		}
	}
	else if (k->q >= 0 && k->w < 0)
	{
		if (5 * tab[k->j][0] - tab[k->j][1] > k->q22)
		{
			k->q22 = 5 * tab[k->j][0] - tab[k->j][1];
			k->i3 = k->j;
		}
	}
	else
	{
		if (-5 * tab[k->j][0] - tab[k->j][1] > k->q22)
		{
			k->q22 = -5 * tab[k->j][0] - tab[k->j][1];
			k->i3 = k->j;
		}
	}
}

void		ft_algo_filler8(t_enf3 *k, int tab[3000][2])
{
	if (k->q < 0 && k->w >= 0)
	{
		if (-tab[k->j][0] + tab[k->j][1] * 5 > k->q22)
		{
			k->q22 = -tab[k->j][0] + tab[k->j][1] * 5;
			k->i3 = k->j;
		}
	}
	else if (k->q >= 0 && k->w < 0)
	{
		if (tab[k->j][0] - tab[k->j][1] * 5 > k->q22)
		{
			k->q22 = tab[k->j][0] - tab[k->j][1] * 5;
			k->i3 = k->j;
		}
	}
	else
	{
		if (-tab[k->j][0] - tab[k->j][1] * 5 > k->q22)
		{
			k->q22 = -tab[k->j][0] - tab[k->j][1] * 5;
			k->i3 = k->j;
		}
	}
}
