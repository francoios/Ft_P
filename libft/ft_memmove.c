/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:10:48 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 13:59:12 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		while (len--)
		{
			((char*)dst)[i] = (((char*)src)[i]);
			i++;
		}
	else
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	return ((void*)dst);
}
