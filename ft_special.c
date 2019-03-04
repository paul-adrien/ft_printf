/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:30:31 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/04 11:44:52 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sp_strnjoin(char *s1, char *s2, size_t n, int mode)
{
	char	*str;

	if (!s1 || !s2 || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		(mode == 0 ? free(s1) : free(s2));
		return (NULL);
	}
	str = ft_strcpy(str, s1);
	(mode == 0 ? free(s1) : free(s2));
	return (ft_strncat(str, s2, n));
}
