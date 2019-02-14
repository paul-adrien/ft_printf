/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:04:54 by pa                #+#    #+#             */
/*   Updated: 2018/11/26 22:04:25 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while ((unsigned char)*s1 == (unsigned char)*s2 && n-- > 0)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if (!n)
		return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
