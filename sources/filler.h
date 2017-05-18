/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:33:55 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 16:12:05 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"

typedef struct	s_enf
{
	int			board_x;
	int			board_y;
	char		**board;
	char		player;
	int			piece_x;
	int			piece_y;
	char		**piece;
	int			max_x;
	int			min_x;
	int			max_y;
	int			min_y;
	int			max_x2;
	int			min_x2;
	int			max_y2;
	int			min_y2;
	int			bpp;
	int			sl;
	int			e;
	int			j;
	char		*data;
	void		*mlx;
	void		*window;
	void		*image;
	int 		x_min8;
	int			y_min8;
	int 		x_max8;
	int			y_max8;
}				t_enf;

typedef struct	s_enf2
{
	int			p_y;
	int			p_x;
	int			z5;
	int			z6;
	int			i;
	int			tmp_x;
}				t_enf2;

typedef struct	s_enf3
{
	int			z;
	int			zz;
	int			zzz;
	int			j;
	int			i4;
	int			i5;
	float		q;
	float		w;
	float		q22;
	float		w22;
	int			i3;
}				t_enf3;

void			check_board(int fd, t_enf *e, char **line);
void			check_board2(t_enf *e);
void			check_board5(int fd, t_enf *e, char **line);
void			check_board7(t_enf *e, int i, int y);
void			check_piece(int fd, t_enf *e, char **line);
int				ft_check_pos(t_enf *e, int y, int x, int *z);
int				ft_check_pos2(t_enf *e, t_enf2 *l, int x, int y);
void			ft_algo_filler2(t_enf *e, int y, t_enf3 *k, int tab[3000][2]);
void			ft_algo_filler7(t_enf3 *k, int tab[3000][2]);
void			ft_algo_filler8(t_enf3 *k, int tab[3000][2]);
void			ft_algo_filler(t_enf *e);

#endif
