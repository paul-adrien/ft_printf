/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:29:05 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/04 14:17:50 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s_width_preci(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;

	// i = taille final de str
	// j = taille de str a ecrire
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

static char		*st_alloc_str2(int i, int j)
{
	char	*str;

	if (i > j)
	{
		if (!(str = ft_strnew(i + 1)))
			return (NULL);
	}
	else
		if (!(str = ft_strnew((i = j) + 1)))
			return (NULL);
	return (str);
}

static char		*st_noflags_(char *str, t_asset asset, int i, int j)
{
	char	*str2;

	if (!(str2 = st_alloc_str2(i, j)))
		return (NULL);
	while (--j >= 0)
		str2[--i] = str[j];
	while (i > 0 && (ft_strchr(asset.flags, '0')))
		str2[--i] = '0';
	while (i > 0 && (!ft_strchr(asset.flags, '0')))
		str2[--i] = ' ';
	if (ft_strchr(asset.flags, '+') && ft_strchr(asset.flags, '0')
			&& str[0] != '-')
		str2[0] = '+';
	else if (ft_strchr(asset.flags, '+') && str[0] != '-')
		str2[i -j - 1] = '+';
	else if (str[0] == '-' && ft_strchr(asset.flags, '0'))
	{
		str2[0] = '-';
		str2[i - j] = '0';
	}
	else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '0'))
		str2[0] = ' ';
	free(str);
	return (str2);
}

char			*ft_width_f(t_asset asset, char *str, int i/*width*/, int j/*strlen*/)
{
	char	*str2;
	int		k;
	int		n;

	n = 0;
	k = -1;
	if (!(str2 = st_alloc_str2(i, j)))
		return (NULL);
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		if (ft_strchr(asset.flags, '+'))
			str2[n++] = '+';
		else if (ft_strchr(asset.flags, ' '))
			str2[n++] = ' ';
		while (++k < j)
			str2[k + n] = str[k];
		while (k + n < i)
			str2[k++ + n] = ' ';
	}
	else
		if (!(str2 = st_noflags_(str, asset, i, j)))
			return (NULL);
	//free qd ?
	return (str2);
}
