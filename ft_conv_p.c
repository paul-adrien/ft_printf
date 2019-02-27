/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:05:22 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/26 18:30:40 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_0x(char *res, int i, t_asset asset)
{
	char	*str;

	str = ft_strnew(i++ + 2);
	if (!ft_strchr(asset.flags, '0'))
	{
		while (--i >= 0)
			str[i + 2] = res[i];
	str[0] = '0';
	str[1] = 'x';
	}
	else
	{
	str[i] = '0';
	str[i + 1] = 'x';
	while (--i >= 0)
		str[i + 2] = res[i];

	}
	return (str);
}

static int	ft_compt(long adr)
{
	int		i;

	i = 0;
	while ((adr / 16) > 0)
	{
		adr /= 16;
		i++;
	}
	return (i);
}

char		*ft_conv_p(t_asset asset, va_list ap) // Remarque Etienne : pas sur que ca marche
{
	long	adr;
	char	*base;
	char	*res;
	size_t	i;

	adr = va_arg(ap, long);
	res = ft_strnew(i = ft_compt(adr) + 2); // Pourquoi i = ft_compt ?
	base = "0123456789abcdef";
	i = 0;
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i++;
	}
	res[i] = base[(adr % 16)];
	if (i < asset.width)
		res = ft_s_width_preci(asset, ft_add_0x(ft_strrev(res), i, asset), asset.width, i + 3);
	else
		res = ft_add_0x(ft_strrev(res), i, asset);
	return (res);
}
