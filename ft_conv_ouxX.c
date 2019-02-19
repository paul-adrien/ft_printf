/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ouxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:26:52 by eviana            #+#    #+#             */
/*   Updated: 2019/02/19 17:40:46 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_converter(t_asset asset, char *str) // MODIFIER ABSOLUMENT FT_CONVERT_BASE (FUCKED UP)
{
	char *str2;

	str2 = str;
	if (asset.type == 2)
	{
		if (!(str = ft_convert_base(str, "0123456789", "01234567")))
			return (NULL);
		else 
			free(str2);
	}
	else if (asset.type == 4)
	{
		if (!(str = ft_convert_base(str, "0123456789", "0123456789abcdef")))
			return (NULL);
		else 
			free(str2);
	}
	else if (asset.type == 5)
	{
		if (!(str = ft_convert_base(str, "0123456789", "0123456789ABCDEF")))
			return (NULL);
		else 
			free(str2);
	}
	return (str);
}

char	*ft_conv_ouxX(t_asset asset, va_list ap)
{
	char		*str;

	ft_putstr("L1 |"); // TEST
	ft_putnbr(asset.length); // TEST
	ft_putstr("|\n"); // TEST
	
	if (asset.length == 1)
	{
		if (!(str = ft_ultoa(va_arg(ap, unsigned long))))
			return (NULL);
	}
	else if (asset.length == 2)
	{
		if (!(str = ft_ulltoa(va_arg(ap, unsigned long long))))
			return (NULL);
	}
	else if (asset.length == 3)
	{
		if (!(str = ft_itoa((unsigned short)va_arg(ap, int)))) // PAS LA MM SORTIE QUE PRINTF QUI SORT UN INT NORMAL
			return (NULL);
	}
	else if (asset.length == 4)
	{
		if (!(str = ft_itoa((unsigned char)va_arg(ap, int)))) // A VERIFIER // PRINTF DONNE INVALID DIRECTIVE
			return (NULL);
	}
	else
	{
		if (!(str = ft_itoa(va_arg(ap, unsigned int))))
			return (NULL);
	}
	if (!(str = ft_converter(asset, str)))
	{
		ft_putstr("test sortie converter\n");
		return (NULL);
	}
	if (!(str = ft_build_str(str, asset, 0))) // signmode = 0 / on ne le traite pas car on traite des unsigned
		return (NULL);
	return (str);
}