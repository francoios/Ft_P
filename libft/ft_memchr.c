/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:52:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 13:58:44 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < n && s)
	{
		if (*((char *)s + i) == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
