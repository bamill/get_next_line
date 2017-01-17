/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:49:29 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 21:49:56 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdrop(t_list *lst, size_t count)
{
	if (count == 0)
		return (ft_lstcpy(lst));
	else
		return (ft_lstdrop(lst->next, count - 1));
}
