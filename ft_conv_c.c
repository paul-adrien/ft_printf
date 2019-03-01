/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:04:48 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/01 18:20:22 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*ft_convp_width(t_asset asset, char *res)
{
	char	*str;
	int		k;
	int		j;

	k = asset.width;
	j = 0;
	str = ft_strnew(k - 1);
	if (ft_strchr(asset.flags, '-'))
	{
		while (++j < i)
			str[j - 1] = res[j];
		j--;
		while (j < i)
			str[j++] = ' ';
		str[i] = '\0';
	}
	else
	{
		while (j < i)
			str[j++] = ' ';
		j = 1;
		while (j <= 8)
			str[i++ - 8] = res[j++];
	}
	return (str);
}*/

char	*ft_s_width_preci(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;
	int		n;

	// i = taille final de str
	// j = taille de str a ecrire
	n = 0;
	k = -1;
	if (i < j && i != 0)
		i = j;
	if (!(str2 = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str2[i] = '\0';
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		while (++k < j)
			str2[k] = str[k];
		while (k < i)
			str2[k++] = ' ';
	}
	else
	{
		k = i;
		while (--j >= 0)
			str2[--k] = str[j];
		if (ft_strchr(asset.flags, '0'))
			while (k > 0)
				str2[--k] = '0';
		else
			while (k > 0)
				str2[--k] = ' ';
	}
	//free(str);
	return (str2);
}

// GERER LE CAS OU LE CARACTERE NULL EST ENVOYER
char	*ft_conv_c(t_asset asset, va_list ap)
{
	char			*str;
	unsigned char	c;
	wint_t			w;
	size_t			width;
	size_t			j;

	j = 0;
	width = asset.width;
	str = ft_strnew(width);// a l'origine width + 2 ?
	if (ft_strchr(asset.flags, 'l'))
	{
		w = va_arg(ap, wint_t);
		//if (!(w = va_arg(ap, wint_t)))
		//	return (0);
		while (j < width)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || width == 0)
			str[0] = (char)w;
		else
			str[--width] = (char)w;
	}
	else
	{
		c = va_arg(ap, int);
		//if (!(c = va_arg(ap, int)) && width < 1) // a voir pour asset.width
		//	return (ft_strnew(0)); // a checker car peut etre dangereux
		if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-'))
			while (j < width)
				str[j++] = '0';
		else //if (ft_strchr(asset.flags, '0')
			while (j < width)
				str[j++] = ' ';
		if ((ft_strchr(asset.flags, '-') || width == 0) && c)
			str[0] = c;
		else
			str[--width] = c;
	}
	//ft_putstr(str);
	return (str);
}
