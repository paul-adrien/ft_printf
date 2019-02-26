/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:40:38 by eviana            #+#    #+#             */
/*   Updated: 2019/02/26 17:18:36 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_percent(t_asset asset, va_list ap)
{
	char	*str;
	unsigned char	c;
	wint_t	w;
	int		i;
	int		j;

	j = 0;
	i = asset.width;
	if (i < 0)
		i = 0;
	str = ft_strnew(i + 2);
	if (ft_strchr(asset.flags, 'l'))
	{
		w = (wint_t)'%';
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = (char)w;
		else
			str[--i] = (char)w;
	}
	else
	{
		c = '%';
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = c;
		else
			str[--i] = c;
	}
	(void)ap;
	return (str);
}
