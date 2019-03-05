/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:07:13 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/05 16:29:02 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*st_width_preci(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;

	// i = taille final de str
	//	// j = taille de str a ecrire
	k = -1;
	if (i < j && i != 0)
		i = j;
	if (!(str2 = ft_strnew(i + 1)))
		return (NULL);
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		while (++k < j)
			str2[k] = str[k];
		while (k < i)
			str2[k++] = ' ';
	}
	else
	{
		while (--j >= 0)
			str2[--i] = str[j];
		while (i > 0 && ft_strchr(asset.flags, '0'))
			str2[--i] = '0';
		while (i > 0 && !ft_strchr(asset.flags, '0'))
			str2[--i] = ' ';
	}
	//free(str); // A NE PAS METTRE CAR UTILISE PAR CONV_S ET CONV_P DE MANIERE DIFFERENTE
	return (str2);
}

char	*ft_conv_s(t_asset asset, va_list ap)
{
	char	*str;
	int		i;//taille de str
	int		k;//taille final de str
	int		j;//taille de str a ecrire

	i = 0;
	k = 0;
	j = asset.precision;
	if(!(str = va_arg(ap, char*)))
	{
		if (!(str = ft_strnew(6)))
			return (NULL);
		str = sp_strnjoin(str, "(null)", 6, 0);
	}
	i = ft_strlen(str);
	if ((int)asset.width > i || (asset.precision < i &&
				asset.precision < (int)asset.width && (int)asset.width > i))
		k = asset.width;
	if (asset.precision >= (int)asset.width && asset.precision < i)
		k = asset.precision;
	if ((int)asset.width > asset.precision && ft_strlen(str) > asset.width)
		k = asset.width;
	if (k == 0 && asset.precision != 0)
		k = i;
	if (j == -1 || j >= i)
		j = i;
	str = st_width_preci(asset, str, k, j);
	return (str);
}
