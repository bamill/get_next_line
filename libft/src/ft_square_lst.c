/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:37:45 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/06 05:18:49 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_square_lst(t_list *lst)
{
	t_list		*list;
	int			n;

	if (!lst)
		return (NULL);
	n = ((*(int*)(lst->content)) * (*(int*)(lst->content)));
	list = ft_lstnew(&n, sizeof(int));
	return (list);
}
