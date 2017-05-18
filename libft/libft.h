/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:26:57 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/12 15:53:11 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);

# define BUFF_SIZE 100000

typedef struct		s_list2
{
	int				fd;
	char			*str;
	struct s_list2	*next;
}					t_list2;

int					get_next_line(int const fd, char **line);

#endif
