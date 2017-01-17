/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:47:42 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/04 13:31:54 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		numlength(int nbr)
{
	int				i;
	long long		tmp;

	i = 0;
	tmp = nbr;
	if (tmp == 0)
		i++;
	if (tmp < 0)
		tmp *= -1;
	while (tmp > 0)
	{
		i++;
		tmp /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*str;
	long long	nb;

	i = (n < 0) ? 1 : 0;
	nb = n;
	i += numlength(n);
	str = (char*)(malloc(i + 1));
	if (!str)
		return (NULL);
	str[0] = (nb == 0) ? '0' : 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = ((nb % 10) + '0');
		nb /= 10;
		i--;
	}
	return (str);
}
