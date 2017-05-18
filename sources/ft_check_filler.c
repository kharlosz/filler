/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:05:13 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:14:15 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_piece3(int p_x, int *x_min8, int *x_max8)
{
	if (p_x < *x_min8)
		*x_min8 = p_x;
	if (p_x > *x_max8)
		*x_max8 = p_x;
}

void		check_piece4(int p_y, int *y_min8, int *y_max8)
{
	if (p_y < *y_min8)
		*y_min8 = p_y;
	if (p_y > *y_max8)
		*y_max8 = p_y;	
}

void		check_piece2(t_enf *e, int x_max8, int y_max8)
{
	int 	x_min8;
	int 	y_min8;
	int 	p_y;
	int 	p_x;

	x_min8 = e->board_x;
	y_min8 = e->board_y;
	p_y = -1;
	while (++p_y < e->piece_y)
	{
		p_x = -1;
		while (++p_x < e->piece_x)
		{
			if (e->piece[p_y][p_x] == '*')
			{
				check_piece3(p_x, &x_min8, &x_max8);
				check_piece4(p_y, &y_min8, &y_max8);
			}
		}
	}
	e->x_min8 = x_min8;
	e->y_min8 = y_min8;
	e->x_max8 = x_max8;
	e->y_max8 = y_max8;
}

void		check_piece(int fd, t_enf *e, char **line)
{
	int 	i;
	int 	y;

	get_next_line(fd, line);
	free(*line);
	while (ft_isdigit(**line) == 0)
		*line += 1;
	e->piece_y = ft_atoi(*line);
	y = e->piece_y;
	while (**line != ' ')
		*line += 1;
	e->piece_x = ft_atoi(*line);
	i = 0;
	e->piece = (char **)malloc(sizeof(char *) * e->piece_y + 1);
	while (i < e->piece_y)
	{
		get_next_line(fd, line);
		e->piece[i] = ft_strdup(*line);
		i++;
		free(*line);
	}
	e->piece[i] = NULL;
	check_piece2(e, 0, 0);
}
