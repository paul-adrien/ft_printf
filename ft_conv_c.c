/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:04:48 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/26 18:07:53 by plaurent         ###   ########.fr       */
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
	return (str2);
}

// ne pas oublier wchar!!!!!!!!

// GERER LE CAS OU LE CARACTERE NULL EST ENVOYER
char	*ft_conv_c(t_asset asset, va_list ap)
{
	char	*str;
	unsigned char	c;
	wint_t	w;
	int		i;
	int		j;

	j = 0;
	i = asset.width;
	if (i < 0)
		i = 0;
	str = ft_strnew(i + 2);
	if (ft_strchr(asset.flags, 'l'))
	{
		if(!(w = va_arg(ap, wint_t)))
			return (0);
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = (char)w;
		else
			str[--i] = (char)w;
	}
	else
	{
		if(!(c = va_arg(ap, int)) && asset.width < 1)
			return(0);
		if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-'))
			while (j < i)
				str[j++] = '0';
		else //if (ft_strchr(asset.flags, '0')
			while (j < i)
				str[j++] = ' ';
		if ((ft_strchr(asset.flags, '-') || i == 0) && c)
			str[0] = c;
		else
			str[--i] = c;
	}
	//ft_putstr(str);
	return (str);
}
