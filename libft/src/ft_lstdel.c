/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:29:42 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/02 23:52:24 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next != NULL)
		ft_lstdel(&((*alst)->next), del);
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	return ;
}
