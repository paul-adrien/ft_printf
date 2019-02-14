/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:33:24 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/29 10:38:23 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	unsigned const char	*src2;
	int					i;

	dest2 = dest;
	src2 = src;
	i = 0;
	if (dest2 < src2)
	{
		while (n-- > 0)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		dest2 += n;
		src2 += n;
		while (n-- > 0)
			*--dest2 = *--src2;
	}
	return (dest2);
}
