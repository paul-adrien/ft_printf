/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:44:15 by pa                #+#    #+#             */
/*   Updated: 2018/11/23 11:21:26 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int		j;
	char	*str1;
	char	*str2;

	if (!*s2)
		return ((char *)s1);
	while (*s1 != '\0' && len-- > 0)
	{
		if (*s1 == *s2)
		{
			str1 = (char *)s1 + 1;
			str2 = (char *)s2 + 1;
			j = len;
			while (j-- > 0 && *str1 && *str2 && *str1 == *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
