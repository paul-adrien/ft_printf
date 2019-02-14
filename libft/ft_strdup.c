/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:56:19 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/29 10:40:08 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*res;

	i = -1;
	res = (char *)malloc(sizeof(char) * (ft_strlen((char *)src) + 1));
	if (!res)
		return (NULL);
	while (src[++i] != '\0')
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}
