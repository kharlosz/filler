/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:45:55 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:12:58 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_board8(t_enf *e, int i, int y)
{
	int		m;
	int		m2;

	if (i < e->min_y2)
		e->min_y2 = i;
	if (y < e->min_x2)
		e->min_x2 = y;
	if (i > e->max_y2)
		e->max_y2 = i;
	if (y > e->max_x2)
		e->max_x2 = y;
	m = 0;
	while (m < 8)
	{
		m2 = 0;
		while (m2 < 8)
		{
			e->data[e->board_x * 40 * i * 10 + y * 40 + m2 * 4 + m * e->board_x * 40] = 5;
			e->data[e->board_x * 40 * i * 10 + y * 40 + m2 * 4 + 1 + m * e->board_x * 40] = 255;
			e->data[e->board_x * 40 * i * 10 + y * 40 + m2 * 4 + 2 + m * e->board_x * 40] = 255;
			m2++;
		}
		m++;
	}
}

void		check_board6(t_enf *e, int i, int y)
{
	if (e->board[i][y] != e->player && e->board[i][y] != e->player - 32 && e->board[i][y] != '.')
		check_board7(e, i, y);
	else if (e->board[i][y] == e->player || e->board[i][y] == e->player - 32)
		check_board8(e, i, y);
}

void		check_board(int fd, t_enf *e, char **line)
{
	int		i;
	int		y;

	while (ft_isdigit(**line) == 0)
		*line += 1;
	e->board_y = ft_atoi(*line);
	while (**line != ' ')
		*line += 1;
	e->board_x = ft_atoi(*line);
	get_next_line(fd, line);
	free(*line);
	if (e->j == 0)
		check_board2(e);
	check_board5(fd, e, line);
	i = 0;
	while (i < e->board_y)
	{
		y = 0;
		while (y < e->board_x)
		{
			check_board6(e, i, y);
			y++;
		}
		i++;
	}
}
