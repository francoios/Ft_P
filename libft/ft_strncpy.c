/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:13:56 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:02:15 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		size;

	i = -1;
	size = ft_strlen(src);
	while (++i < n)
	{
		if (i > size)
			dst[i] = '\0';
		else
			dst[i] = src[i];
	}
	return (dst);
}
