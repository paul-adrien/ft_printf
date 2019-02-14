/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:30:47 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/29 10:39:55 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	int					k;
	int					i;

	i = 0;
	k = 0;
	str1 = s1;
	str2 = s2;
	while (n-- > 0)
	{
		if (str1[i] != str2[i])
			return (k = str1[i] - str2[i]);
		i++;
	}
	return (0);
}
