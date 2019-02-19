/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:07:13 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/19 18:17:51 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if ((int)asset.width > i ||
			(asset.precision < i && asset.precision < (int)asset.width && (int)asset.width > i))
		k = asset.width;
	if (asset.precision >= (int)asset.width && asset.precision < i)
		k = asset.precision;
	if (k == 0 && asset.precision != 0)
		k = i;
	if (j == -1 || j >= i)
		j = i;
	str = ft_s_width_preci(asset, str, k, j);
	//ft_putstr(str);
	return (str);
}
