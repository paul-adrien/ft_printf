/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:07:13 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/14 12:12:30 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_conv_s(t_asset asset, va_list ap)
{
	char	*str;
	int		i;//taille de str
	int		k;//taille final de str
	int		j;//taille de str a ecrire

	i = 0;
	k = 0;
	j = asset.precision;
	str = va_arg(ap, char*);
	i = ft_strlen(str);
	if (asset.width > i ||
			(asset.precision < i && asset.precision < asset.width && asset.width > i))
		k = asset.width;
	if (asset.precision >= asset.width && asset.precision < i)
		k = asset.precision;
	if (k == 0)
		k = i;
	if (j == -1 || j >= i)
		j = i;
	ft_putstr(str = ft_s_width_preci(asset, str, k + 1, j));
	return (str);
}
