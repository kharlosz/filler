/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:52:58 by carodrig          #+#    #+#             */
/*   Updated: 2016/02/15 18:38:41 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

t_list2		*init(t_list2 *list, int const fd, int i)
{
	if (list == NULL)
	{
		if (!(list = (t_list2 *)malloc(sizeof(t_list2))))
			return (NULL);
		if (!(list->str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
		list->fd = fd;
		list->next = NULL;
		while (i < BUFF_SIZE + 1)
			list->str[i++] = '\0';
	}
	return (list);
}

t_list2		*verif_maillon(t_list2 *list, int const fd, int i)
{
	t_list2		*new;
	t_list2		*temp;

	new = list;
	while (new && new->fd != fd)
	{
		temp = new;
		new = new->next;
	}
	if (!new)
	{
		if (!(new = (t_list2 *)malloc(sizeof(t_list2))))
			return (NULL);
		temp->next = new;
		if (!(new->str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
		new->fd = fd;
		new->next = NULL;
		while (i < BUFF_SIZE + 1)
			new->str[i++] = '\0';
	}
	return (new);
}

int			algo2(t_list2 **lemp, char *temp, char **line, size_t i)
{
	int		j;
	char	*s3;

	j = 0;
	while (j < BUFF_SIZE + 1)
		temp[j++] = '\0';
	j = read((*lemp)->fd, temp, BUFF_SIZE);
	if (j != 0 && j != -1)
	{
		s3 = ft_strjoin((*lemp)->str, temp);
		free((*lemp)->str);
		(*lemp)->str = s3;
		free(temp);
	}
	else if (j == 0)
	{
		*line = ft_strsub((*lemp)->str, 0, i);
		temp = ft_strsub((*lemp)->str, i, ft_strlen((*lemp)->str));
		free((*lemp)->str);
		(*lemp)->str = temp;
		return (i == 0 ? 0 : 1);
	}
	else
		return (-1);
	return (2);
}

int			algo(t_list2 *lemp, size_t i, char **line, int j)
{
	char	*temp;

	temp = NULL;
	while (i < ft_strlen(lemp->str) + 1)
	{
		if (lemp->str[i] == '\n')
		{
			*line = ft_strsub(lemp->str, 0, i);
			temp = ft_strsub(lemp->str, i + 1, ft_strlen(lemp->str));
			free(lemp->str);
			lemp->str = temp;
			return (1);
		}
		else if (lemp->str[i] == '\0')
		{
			if (!(temp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
				return (-1);
			j = algo2(&lemp, temp, line, i);
			if (j == 1 || j == 0 || j == -1)
				return (j);
		}
		else
			i++;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static t_list2		*list = NULL;
	t_list2				*lemp;
	size_t				i;

	if (fd < 0 || line == 0)
		return (-1);
	*line = NULL;
	list = init(list, fd, 0);
	lemp = verif_maillon(list, fd, 0);
	i = 0;
	return (algo(lemp, 0, line, 10));
}
