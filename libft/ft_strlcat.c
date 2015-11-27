/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:33:48 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:01:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = ft_strlen(dst);
	if (b >= size)
		return (size + ft_strlen(src));
	while ((i < size - b - 1) && src[i])
	{
		dst[b + i] = src[i];
		i++;
	}
	dst[b + i] = '\0';
	return (ft_strlen(src) + b);
}
