/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:13:57 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:03:34 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(fraiche = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		fraiche[i] = s[start];
		start++;
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
