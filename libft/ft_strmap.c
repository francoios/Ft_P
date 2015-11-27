/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:18:37 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:01:48 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraiche;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(fraiche = (char*)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		fraiche[i] = f(s[i]);
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
