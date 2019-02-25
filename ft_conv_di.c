/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:26:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/25 17:36:52 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_asset asset, va_list ap)
{
	char	*str;

	if (asset.length == 1)
	{
		if (!(str = ft_ltoa(va_arg(ap, long int))))
			return (NULL);
	}
	else if (asset.length == 2)
	{
		if (!(str = ft_lltoa(va_arg(ap, long long))))
			return (NULL);
	}
	else if (asset.length == 3)
	{
		if (!(str = ft_itoa((short)va_arg(ap, int))))
			return (NULL);
	}
	else if (asset.length == 4)
	{
		if (!(str = ft_itoa((char)va_arg(ap, int))))
			return (NULL);
	}
	else
	{
		if (!(str = ft_itoa(va_arg(ap, int))))
			return (NULL);
	}
	if (!(str = ft_build_str(str, asset, 1)))
		return (NULL);
	return (str);
}
