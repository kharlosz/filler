/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:02:19 by carodrig          #+#    #+#             */
/*   Updated: 2016/02/15 18:14:10 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	char	*s3;

	i = 0;
	if (s1)
		i = ft_strlen(s1);
	if (s2)
		i += ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (i + 1));
	return (s3);
}

static char		*ft_strjoin3(char const *s1, char *s3)
{
	int i;

	i = 0;
	if (s3)
	{
		if (s1)
		{
			while (s1[i])
			{
				s3[i] = s1[i];
				i++;
			}
		}
	}
	return (s3);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = ft_strlen(s1);
	j = 0;
	s3 = ft_strjoin2(s1, s2);
	s3 = ft_strjoin3(s1, s3);
	if (s3)
	{
		if (s2)
		{
			while (s2[j])
				s3[i++] = s2[j++];
		}
		if (s1 || s2)
			s3[i] = '\0';
	}
	return (s3);
}
