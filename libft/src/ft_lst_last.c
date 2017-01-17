/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:54:36 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/07 18:56:18 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst->content);
	return (ft_lst_last(lst->next));
}
