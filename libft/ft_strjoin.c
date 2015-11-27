/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:16:40 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:01:25 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*fraiche;
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(fraiche = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		fraiche[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		fraiche[i] = s2[b];
		b++;
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
