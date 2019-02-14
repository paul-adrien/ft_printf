/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:50:26 by pa                #+#    #+#             */
/*   Updated: 2018/11/29 10:42:31 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (dest[nb] != '\0')
		nb++;
	while (n-- > 0 && src[i] != '\0')
	{
		dest[nb] = src[i];
		i++;
		nb++;
	}
	dest[nb] = '\0';
	return (dest);
}
