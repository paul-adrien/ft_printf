/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:26:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/19 15:42:16 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_asset asset, va_list ap) // ap pas en pointeur
{
	char		*str;
	//	long		l;
	//	long long	ll;
	//	short		h;
	//	signed char hh;

	ft_putstr("L1 |"); // TEST
	ft_putnbr(asset.length); // TEST
	ft_putstr("|\n"); // TEST
	if (asset.length == 1)
	{
		if (!(str = ft_ltoa(va_arg(ap, long)))) // FAIRE NOTRE PROPRE LTOA
			return (NULL);
	}
	else if (asset.length == 2)
	{
		if (!(str = ft_lltoa(va_arg(ap, long long))))
			return (NULL);
	}
	else if (asset.length == 3)
	{
		if (!(str = ft_itoa((short)va_arg(ap, int)))) // PAS LA MM SORTIE QUE PRINTF QUI SORT UN INT NORMAL
			return (NULL);
	}
	else if (asset.length == 4)
	{
		if (!(str = ft_itoa((char)va_arg(ap, int)))) // A VERIFIER // PRINTF DONNE INVALID DIRECTIVE
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
