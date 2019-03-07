/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:17:34 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/06 18:19:01 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_inf_f(t_asset asset, char *str2, size_t i, int j)
{
	char	*str;

	if (ft_strlen(str2) > asset.width)
		i = ft_strlen(str2);
	else
		i = asset.width;
	if (!(str = ft_strnew(i)))
		return (NULL);
	i = -1;
	if (ft_strchr(asset.flags, '-'))
	{
		while (str2[++i])
			str[i] = str2[i];
		while (i < asset.width)
			str[i++] = ' ';
	}
	else
	{
		while (i + 1 < (asset.width - ft_strlen(str2))
				&& asset.width > ft_strlen(str2))
			str[++i] = ' ';
		while (str2[j])
			str[++i] = str2[j++];
	}
	return (str);
}