/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:16:48 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:02:46 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	while (i < n - 1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((s2[i] || s1[i]) && s1[i] != s2[i])
		return (0);
	return (1);
}
