/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:29:05 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/01 11:54:38 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_width_f(t_asset asset, char *str, int i/*width*/, int j/*strlen*/)
{
	char	*str2;
	int		k;
	int		n;

	n = 0;
	k = -1;
	if (i > j)
	{
		if (!(str2 = ft_strnew(i + 1)))
			return (NULL);
	}
	else
	{
		if(!(str2 = ft_strnew(j + 1)))
			return (NULL);
		i = j;
	}
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
	{
		n = i - j;
		k = i;
		while (--j >= 0)
			str2[--k] = str[j];
		while (k > 0)
		{
			if (ft_strchr(asset.flags, '0'))
				str2[--k] = '0';
			else
				str2[--k] = ' ';
		}
		if (ft_strchr(asset.flags, '+') && ft_strchr(asset.flags, '0')
				&& str[0] != '-')
			str2[0] = '+';
		else if (ft_strchr(asset.flags, '+') && str[0] != '-')
			str2[n - 1] = '+';
		else if (str[0] == '-' && ft_strchr(asset.flags, '0'))
		{
			str2[0] = '-';
			str2[n] = '0';
		}
		else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '0'))
			str2[0] = ' ';
	}
	return (str2);
}
