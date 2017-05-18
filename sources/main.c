/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 10:34:25 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:15:32 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_destroy(t_enf *e)
{
	int 	i;

	i = -1;
	while (++i < e->board_y)
		free(e->board[i]);
	free(e->board);
	i = -1;
	while (++i < e->piece_y)
		free(e->piece[i]);
	free(e->piece);
}

int			lolita(void *e)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			free(line);
			check_board(0, (t_enf *)e, &line);
			check_piece(0, (t_enf *)e, &line);
			ft_algo_filler((t_enf *)e);
			mlx_clear_window(((t_enf *)e)->mlx, ((t_enf *)e)->window);
			mlx_put_image_to_window(((t_enf *)e)->mlx, ((t_enf *)e)->window, ((t_enf *)e)->image, 0, 0);
			ft_destroy((t_enf *)e);
		}
		else
			free(line);
	}
	else
	{
		mlx_destroy_image(((t_enf *)e)->mlx, ((t_enf *)e)->image);
		mlx_destroy_window(((t_enf *)e)->mlx, ((t_enf *)e)->window);
		free((t_enf *)e);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int			main()
{
	t_enf	*e;
	char	*line;

	line = NULL;
	e = (t_enf *)malloc(sizeof(t_enf));
	e->mlx = mlx_init();
	e->j = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$')
		{
			if (ft_strstr(line, "$$$ exec p1"))
				e->player = 'o';
			else
				e->player = 'x';
			free(line);
		}
	}
	mlx_loop_hook(e->mlx, lolita, e);
	mlx_loop(e->mlx);
	return (0);
}
