/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:05:22 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/06 11:42:33 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*st_width_preci(t_asset asset, char *str, int i, int j)
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

static char	*ft_add_0x(char *initial, int i, t_asset asset)
{
	char	*str;

	if (!(str = ft_strnew(i + 3)))
		return (NULL); // +3 pour laisser la place au \0 car un i++ a ete oublie plus bas
	i++;
	if (!ft_strchr(asset.flags, '0'))
	{
		while (--i >= 0)
			str[i + 2] = initial[i];
		str[0] = '0';
		str[1] = 'x';
	}
	else
	{
		str[i] = '0';
		str[i + 1] = 'x';
		while (--i >= 0)
			str[i + 2] = initial[i];
	}
	ft_strdel(&initial);
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
	char	*final;
	char	*additional;
	size_t	i;

	adr = va_arg(ap, long);
	final = ft_strnew(i = ft_compt(adr) + 2); // Pourquoi i = ft_compt ?
	base = "0123456789abcdef";
	i = 0;
	while ((adr / 16) > 0)
	{
		final[i] = base[(adr % 16)];
		adr /= 16;
		i++;
	}
	final[i] = base[(adr % 16)]; // voir plus haut (un i++ aurait du arriver ici sinon)
	if (i < asset.width)
	{
		if (!(additional = ft_add_0x(ft_strrev(final), i, asset)))
			return (NULL);
		if (!(final = st_width_preci(asset, additional, asset.width, i + 3)))	// FUITE MEMOIRE AVEC RES A CORRIGER
		{
			free(additional);
			return (NULL);
		}
		ft_strdel(&additional);
	}
	else
		final = ft_add_0x(ft_strrev(final), i, asset); // FUITE MEMOIRE A GERER
	return (final);
}
