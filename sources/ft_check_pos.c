/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_filler2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:34:22 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:14:08 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_check_pos9(t_enf *e, t_enf2 *l, int x, int y)
{
	while (++l->p_y < e->y_max8 + 1 && ++y < e->board_y)
	{
		l->p_x = -1;
		x = l->tmp_x;
		while (++l->p_x < e->x_max8 + 1 && ++x < e->board_x + 1)
		{
			l->z6 = 0;
			if (e->piece[l->p_y][l->p_x] == '*')
			{
				if (e->board[y][x - 1] == e->player || e->board[y][x - 1] == e->player - 32)
					l->i++;
			}
			if (!ft_check_pos2(e, l, x, y))
				return (0);
		}
	}
	return (1);
}

int			ft_check_pos(t_enf *e, int y , int x, int *z)
{
	t_enf2	*l;
	char	*line;

	line = NULL;
	l = (t_enf2 *)malloc(sizeof(t_enf2));
	l->tmp_x = x;
	l->i = 0;
	y--;
	l->p_y = -1;
	l->z5 = 0;
	if (!ft_check_pos9(e, l, x, y))
		return (0);
	if (l->i == 1 && l->p_y == e->y_max8 + 1 && l->p_x == e->x_max8 + 1)
	{
		*z = l->z5;
		free(l);
		return (1);
	}
	free(l);
	return (0);
}
