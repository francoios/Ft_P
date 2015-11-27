/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:55:47 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 14:01:53 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		fraiche[i] = f(i, s[i]);
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
