/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:48:07 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/16 20:40:57 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_strtolst(char *str)
{
	t_list *lst;

	if (!str || !(*str))
		return (NULL);
	lst = ft_lstnew(str, sizeof(*str));
	lst->next = ft_strtolst(str + 1);
	return (lst);
}
