/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 13:46:26 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/12 13:49:19 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tab_cpy(char **tab)
{
	int			i;
	char		**new_tab;

	i = -1;
	new_tab = (char **)malloc(sizeof(char *) * tab_lenght(tab) + 1);
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i] = NULL;
	return (new_tab);
}
