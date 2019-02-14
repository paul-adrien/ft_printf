/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:55:08 by pa                #+#    #+#             */
/*   Updated: 2018/11/29 10:43:49 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t j;

	if (*s2 == '\0')
		return ((char *)s1);
	if (!s2)
		return ((char *)s1);
	j = ft_strlen((char*)s2);
	while (*s1 != '\0')
	{
		if (ft_strncmp(s1, s2, j) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
