/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:36:25 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:14:33 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		lolita87(t_enf2 *l)
{
	l->z5 += 3;
	l->z6++;
}

void		ft_check_pos3(t_enf *e, t_enf2 *l, int x, int y)
{
	if (y > 0)
	{
		if (e->board[y - 1][x - 1] != e->player && e->board[y - 1][x - 1] != e->player - 32 && e->board[y - 1][x - 1] != '.')
			lolita87(l);
		else if (e->board[y - 1][x - 1] != '.')
			l->z5--;
	}
	if (y < e->board_y - 1)
	{
		if (e->board[y + 1][x - 1] != e->player && e->board[y + 1][x - 1] != e->player - 32 && e->board[y + 1][x - 1] != '.')
			lolita87(l);
		else if (e->board[y + 1][x - 1] != '.')
			l->z5--;
	}
	if (x > 1)
	{
		if (e->board[y][x - 2] != e->player && e->board[y][x - 2] != e->player - 32 && e->board[y][x - 2] != '.')
			lolita87(l);
		else if (e->board[y][x - 2] != '.')
			l->z5--;
	}
}

void		ft_check_pos4(t_enf *e, t_enf2 *l, int x, int y)
{
	if (x < e->board_x)
	{
		if (e->board[y][x] != e->player && e->board[y][x] != e->player - 32 && e->board[y][x] != '.')
			lolita87(l);
		else if (e->board[y][x] != '.')
			l->z5--;
	}
	if (y > 0 && x > 1)
	{
		if (e->board[y - 1][x - 2] != e->player && e->board[y - 1][x - 2] != e->player - 32 && e->board[y - 1][x - 2] != '.')
			l->z5 += 3;
		else if (e->board[y - 1][x - 2] != '.')
			l->z5--;
	}
	if (y < e->board_y - 1 && x > 1)
	{
		if (e->board[y + 1][x - 2] != e->player && e->board[y + 1][x - 2] != e->player - 32 && e->board[y + 1][x - 2] != '.')
			l->z5 += 3;
		else if (e->board[y + 1][x - 2] != '.')
			l->z5--;
	}
}

void		ft_check_pos5(t_enf *e, t_enf2 *l, int x, int y)
{
	if (x < e->board_x && y > 0)
	{
		if (e->board[y - 1][x] != e->player && e->board[y - 1][x] != e->player - 32 && e->board[y - 1][x] != '.')
			l->z5 += 3;
		else if (e->board[y - 1][x] != '.')
			l->z5--;
	}
	if (x < e->board_x && y < e->board_y - 1)
	{
		if (e->board[y + 1][x] != e->player && e->board[y + 1][x] != e->player - 32 && e->board[y + 1][x] != '.')
			l->z5 += 3;
		else if (e->board[y + 1][x] != '.')
			l->z5--;
	}
}

int			ft_check_pos2(t_enf *e, t_enf2 *l, int x, int y)
{
	if (e->piece[l->p_y][l->p_x] == '*')
	{
		ft_check_pos3(e, l, x, y);
		ft_check_pos4(e, l, x, y);
		ft_check_pos5(e, l, x, y);
	}
	if (e->piece[l->p_y][l->p_x] == '*' && e->board[y][x - 1] != '.' && e->board[y][x - 1] != e->player && e->board[y][x - 1] != e->player - 32)
	{
		free(l);
		return (0);
	}
	if (l->z6 >= 2)
		l->z5 += 4;
	return (1);
}
