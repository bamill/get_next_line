/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:52:14 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 21:52:54 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lsttake(t_list *lst, size_t count)
{
	t_list	*list;

	if (count == 0)
		return (NULL);
	list = ft_lstnew(lst->content, lst->content_size);
	list->next = ft_lsttake(lst->next, count - 1);
	return (list);
}
