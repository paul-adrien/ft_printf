/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:02:18 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/29 10:39:02 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		m;
	int					i;

	i = 0;
	str = s;
	m = c;
	while (n-- > 0)
	{
		if (*str == m)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
