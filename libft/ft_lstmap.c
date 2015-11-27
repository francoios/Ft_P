/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:51:11 by frcugy            #+#    #+#             */
/*   Updated: 2015/04/28 13:58:19 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fraiche;
	t_list		*cursor;
	t_list		*tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(fraiche = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		cursor = fraiche;
		while (lst->next)
		{
			tmp = f(lst->next);
			if (!(fraiche->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			lst = lst->next;
			fraiche = fraiche->next;
		}
		return (cursor);
	}
	return (NULL);
}
