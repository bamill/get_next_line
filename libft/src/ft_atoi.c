/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:06:48 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/29 09:30:22 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	_Bool				neg_p;
	long long			result;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	neg_p = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg_p = 1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	if (neg_p)
		result *= -1;
	return (result);
}
