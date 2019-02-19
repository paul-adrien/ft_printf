/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:38:09 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/19 16:22:48 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_asset		ft_digest(char *tab) // (no_conv exclus en amont)
{
	t_asset	asset;
	size_t	i;

	i = 0;
	if (!(asset.flags = ft_findflags(tab, &i)))
	{
		asset.type = -1;
		return (asset);
	}
	asset.width = ft_findwidth(tab, &i);
	asset.precision = ft_findprecision(tab, &i);
	asset.length = ft_findlength(tab, &i);
	asset.type = ft_findtype(tab, i); // IF PAS BON CHAR A LA FIN => wrong format
	return (asset);
}

char	*ft_dispatcher(char **tab, va_list ap) // Pour dispatcher par les conversions possibles
{
	char	*(*list_ft[7])(t_asset, va_list);
	char	*print[2];
	t_asset	asset;
	size_t	n;
	int		i;

	//list_ft[0] = &ft_no_conv;
	list_ft[1] = &ft_conv_di;
	list_ft[2] = &ft_conv_ouxX;
	list_ft[3] = &ft_conv_c;
	list_ft[4] = &ft_conv_s;
	list_ft[5] = &ft_conv_p;
	//list_ft[6] = &ft_conv_f;
	i = 0;
	if (!(print[0] = ft_strnew(0)))
		return (NULL);
	while (tab[i])
	{
		if ((n = ft_findtype(tab[i], 0)) == -1)
			return (NULL);
		n = (n == 2 || n == 3 || n == 4 || n == 5 ? 2 : n);
		if (n > 0)
		{
			asset = ft_digest(tab[i]);
			if (asset.type == -1)
				return (NULL);
			if (!(print[1] = list_ft[n](asset, ap)))
				return (NULL);
			if (!(print[0] = sp_strnjoin(print[0], print[1], ft_strlen(print[0]) + ft_strlen(print[1]), 0)))
				return (NULL);
			//ft_printasset(asset);
			free(asset.flags);
		}
		else
			if (!(print[0] = sp_strnjoin(print[0], tab[i], ft_strlen(print[0]) + ft_strlen(tab[i]), 0)))
				return (NULL);
		// if ((asset.type == 0))
		//		// FREE ASSET SUR 2 DIMENSIONS
		i++; // A VERIFIER
	}
	return (print[0]);
}
