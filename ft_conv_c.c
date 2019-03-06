/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:04:48 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/06 15:27:05 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_c(t_asset asset, va_list ap)
{
	char			*str;
	unsigned char	c;
	size_t			width;
	size_t			j;

	j = 0;
	width = asset.width;
	str = ft_strnew(width);
	c = va_arg(ap, int);
	if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-'))
		while (j < width)
			str[j++] = '0';
	else
		while (j < width)
			str[j++] = ' ';
	if ((ft_strchr(asset.flags, '-') || width == 0) && c)
		str[0] = c;
	else
		str[--width] = c;
	return (str);
}
