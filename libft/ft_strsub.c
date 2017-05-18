/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:39:52 by carodrig          #+#    #+#             */
/*   Updated: 2016/05/18 13:25:11 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (s && len && s2)
	{
		while (len--)
			s2[i++] = s[start++];
		s2[i] = '\0';
	}
	else if (s2)
		s2[0] = '\0';
	return (s2);
}
