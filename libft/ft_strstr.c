/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:02:56 by carodrig          #+#    #+#             */
/*   Updated: 2015/12/22 16:01:15 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + j] == s2[j] && s2[j])
			j++;
		if (!s2[j])
			return ((char *)s1 + i);
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
