/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:38:48 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 21:58:09 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_lstfold(t_list *lst, void *(*f)(void *e1, void *e2))
{
	t_list	*list;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst->content);
	list = ft_lstnew(f(lst->content, lst->next->content), sizeof(lst->content) \
					+ sizeof(lst->next->content));
	list->next = lst->next->next;
	return (ft_lstfold(list, f));
}
