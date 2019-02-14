/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:01:27 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/29 10:37:28 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest2;
	const char	*src2;

	i = 0;
	dest2 = dest;
	src2 = src;
	while (n > 0)
	{
		dest2[i] = src2[i];
		i++;
		n--;
	}
	return (dest);
}
