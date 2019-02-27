/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:38:09 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/27 14:27:47 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_asset		ft_digest(char *tab) // (no_conv exclus en amont)
{
	t_asset	asset;
	size_t	i;

	i = 0;
	if (!(asset.flags = ft_findflags(tab, i)))
	{
		asset.type = -1;
		return (asset);
	}
	asset.width = ft_findwidth(tab, i);
	asset.precision = ft_findprecision(tab, i);
	asset.length = ft_findlength(tab, i);
	asset.type = ft_findtype(tab, i); // IF PAS BON CHAR A LA FIN => wrong format
	if (!(asset.copy = ft_strsub(tab, 0, ft_strlen(tab)))) // NE PAS OUBLIER DE LE FREE
		asset.copy = ft_strnew(0);
	return (asset);
}

char	*ft_dispatcher(char **tab, va_list ap) // Pour dispatcher par les conversions possibles
{
	char	*(*list_ft[8])(t_asset, va_list);
	char	*print[2]; // ne pas oublier de free print[1] qui est temporaire
	t_asset	asset;
	size_t	n;
	int		i;

	list_ft[0] = &ft_noconv;
	list_ft[1] = &ft_conv_di;
	list_ft[2] = &ft_conv_oux;
	list_ft[3] = &ft_conv_c;
	list_ft[4] = &ft_conv_s;
	list_ft[5] = &ft_conv_p;
	list_ft[6] = &ft_conv_f;
	list_ft[7] = &ft_conv_percent;
	i = 0;
	if (!(print[0] = ft_strnew(0)))
		return (NULL);
	while (tab[i])
	{
		if ((n = ft_findtype(tab[i], 0)) == -1)
			return (NULL);
		n = (n == 21 || n == 22 || n == 23 || n == 24 ? 2 : n);
//		if (n >= 0)
//		{
			asset = ft_digest(tab[i]);
			if (asset.type == -1)
				return (NULL);
			if (!(print[1] = list_ft[n](asset, ap)))
				return (NULL);
			if (!(print[0] = sp_strnjoin(print[0], print[1], ft_strlen(print[0]) + ft_strlen(print[1]), 0)))
				return (NULL); // free print[1] avant de return ?
			//free(print[1]);
			free(asset.flags);
//		}
//		else
//			if (!(print[0] = sp_strnjoin(print[0], tab[i], ft_strlen(print[0]) + ft_strlen(tab[i]), 0)))
//				return (NULL);
		// if ((asset.type == 0))
		//		// FREE ASSET SUR 2 DIMENSIONS
		i++; // A VERIFIER
	}
	return (print[0]);
}
