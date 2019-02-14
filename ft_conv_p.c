/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:05:22 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/14 12:08:02 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_conv_p(t_asset asset, va_list ap)
{
	long	adr;
	char	*base;
	char	res[9];
	int		i;

	adr = va_arg(ap, long);
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	if (asset.width > 8)
		ft_putstr(ft_convp_width(asset, res));
	else
	{
		//ft_putstr("0x7fff");
		while (i < 9)
			ft_putchar(res[i++]);
	}
	return (base);
}
