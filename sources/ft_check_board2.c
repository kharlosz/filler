/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_board2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:47:24 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:13:12 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_board3(t_enf *e, int m, int m2)
{
	m = 0;
	while (m < e->board_y * 10)
	{
		m2 = 0;
		while (m2 < e->board_x)
		{
			e->data[e->board_x * 40 * m + m2 * 4 * 10] = 255;
			e->data[e->board_x * 40 * m + m2 * 4 * 10 + 1] = 255;
			e->data[e->board_x * 40 * m + m2 * 4 * 10 + 2] = 255;
			m2++;
		}
		m++;
	}
}

void		check_board2(t_enf *e)
{
	int		m;
	int		m2;

	e->j = 1;
	e->image = mlx_new_image(e->mlx, e->board_x * 10, e->board_y * 10);
	e->data = mlx_get_data_addr(e->image, &e->bpp, &e->sl, &e->e);
	e->window = mlx_new_window(e->mlx, e->board_x * 10, e->board_y * 10, "Filler (carodrig is yellow)");
	m = 0;
	while (m < e->board_y)
	{
		m2 = 0;
		while (m2 < e->board_x * 10)
		{
			e->data[e->board_x * 40 * m * 10 + m2 * 4] = 255;
			e->data[e->board_x * 40 * m * 10 + m2 * 4 + 1] = 255;
			e->data[e->board_x * 40 * m * 10 + m2 * 4 + 2] = 255;
			m2++;
		}
		m++;
	}
	check_board3(e, m, m2);
}

void		check_board5(int fd, t_enf *e, char **line)
{
	int		i;

	e->board = (char **)malloc(sizeof(char *) * e->board_y + 1);
	i = 0;
	while (i < e->board_y)
	{
		get_next_line(fd, line);

		e->board[i] = ft_strdup(*line + 4);
		i++;
		free(*line);
	}
	e->board[i] = NULL;
	e->min_x = e->board_x;
	e->min_y = e->board_y;
	e->max_x = 0;
	e->max_y = 0;
	e->min_x2 = e->board_x;
	e->min_y2 = e->board_y;
	e->max_x2 = 0;
	e->max_y2 = 0;
}

void		check_board7(t_enf *e, int i, int y)
{
	int		m;
	int		m2;

	if (i < e->min_y)
		e->min_y = i;
	if (y < e->min_x)
		e->min_x = y;
	if (i > e->max_y)
		e->max_y = i;
	if (y > e->max_x)
		e->max_x = y;
	m = 0;
	while (m < 8)
	{
		m2 = 0;
		while (m2 < 8)
		{
			e->data[e->board_x * 40 * i * 10 + y * 40 + m2 * 4 + m * e->board_x * 40] = 255;
			e->data[e->board_x * 40 * i * 10 + y * 40 + m2 * 4 + 1 + m * e->board_x * 40] = 255;
			e->data[e->board_x * 40 * i * 10 + y * 40 + m2 * 4 + 2 + m * e->board_x * 40] = 10;
			m2++;
		}
		m++;
	}
}
