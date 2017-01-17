/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:48:13 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 17:58:28 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(const char *str, char c)
{
	int		i;
	int		count;
	_Bool	in;

	count = 0;
	in = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (in == 1)
			{
				count++;
				in = 0;
			}
		}
		else if (in == 0)
			in = 1;
		i++;
	}
	if ((str[i - 1] != c) && (i != 0))
		count++;
	return (count);
}

static char		*my_strcpy(char *dest, const char *src, char c)
{
	int i;

	i = 0;
	while (src[i] && (src[i] != c))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		my_strlen_c(const char *str, char c)
{
	int n;

	n = 0;
	while (str[n] && (str[n] != c))
	{
		n++;
	}
	return (n);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	char	*st;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	str = (char**)(malloc((sizeof(char*) * count_words(s, c)) + 1));
	if (!str)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[k] == c)
			k++;
		st = (char*)(malloc(sizeof(char) * my_strlen_c(&s[k], c) + 1));
		str[i] = st;
		my_strcpy(st, &s[k], c);
		k += my_strlen_c(s + k, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
