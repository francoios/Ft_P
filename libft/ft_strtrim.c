/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:38:17 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:03:48 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strtrim(char const *s)
{
	char			*fraiche;
	unsigned int	i;
	int				b;
	int				c;

	b = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	c = ft_strlen(s) - 1;
	if (!(fraiche = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(1));
	while (s[b])
	{
		if (ft_isspace(s[c]) == 1)
			c--;
		b++;
	}
	c = c - i + 1;
	fraiche = ft_strsub(s, i, c);
	return (fraiche);
}
