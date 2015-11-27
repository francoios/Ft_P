/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:36:51 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:03:07 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t end;

	end = ft_strlen(s);
	while (end > 0)
	{
		if (s[end] == (char)c)
			return ((char *)s + end);
		end--;
	}
	if (s[end] == (char)c)
		return ((char *)s + end);
	return (NULL);
}
