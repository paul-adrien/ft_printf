/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:24:01 by pa                #+#    #+#             */
/*   Updated: 2018/11/20 23:05:28 by pa               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	t;

	t = 0;
	if (!s)
		return (NULL);
	while (s[t] != '\0')
		t++;
	str = (char *)malloc(sizeof(char) * (t + 1));
	if (!str)
		return (NULL);
	str[t] = '\0';
	t = -1;
	if (!str)
		return (NULL);
	while (s[++t] != '\0')
		str[t] = (*f)(s[t]);
	return (str);
}
