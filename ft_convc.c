/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:04:48 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/12 18:50:08 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convp_width(t_asset asset, char *res)
{
	char	*str;
	int		i;
	int		j;

	i = asset.width;
	j = 0;
	str = ft_strnew(i - 1);
	if (ft_strchr(asset.flags, '-'))
	{
		ft_putstr("0x7fff");
		while (++j < 9)
			str[j - 1] = res[j];
		j--;
		while (j < i)
			str[j++] = ' ';
		str[i] = '\0';
	}
	else
	{
		ft_putstr("0x7fff");
		while (j < i)
			str[j++] = ' ';
		j = 1;
		while (j <= 8)
			str[i++ - 8] = res[j++];
	}
	return (str);
}

char	*ft_conv_p(t_asset asset, va_list ap)
{
	unsigned int  adr;
	char          *base;
	char          res[9];
	int           i;

	adr = va_arg(ap, unsigned int);
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
		ft_putstr("0x7fff");
		while (i < 9)
			ft_putchar(res[i++]);
	}
	return (base);
}

char	*ft_s_width_preci(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;
	int		n;

	n = 0;
	k = -1;
	ft_putnbr(i);
	ft_putnbr(j);
	str2 = malloc(sizeof(char) * (i + 1));
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
		while (k > 0)
			str2[--k] = ' ';
	}
	return (str2);
}

// ne pas oublier wchar!!!!!!!!
char	*ft_conv_s(t_asset asset, va_list ap)
{
	char	*str;
	int		i;//taille de str
	int		k;//taille final de str
	int		j;//taille de str a ecrire

	i = 0;
	k = 0;
	j = asset.precision;
	str = va_arg(ap, char*);
	i = ft_strlen(str);
	if (asset.width > i ||
			(asset.precision < i && asset.precision < asset.width && asset.width > i))
		k = asset.width;
	if (asset.precision >= asset.width && asset.precision < i)
		k = asset.precision;
	if (k == 0)
		k = i;
	if (j == -1 || j >= i)
		j = i;
	str = ft_s_width_preci(asset, str, k, j);
	ft_putstr(str);
	return (str);
}


// GERER LE CAS OU LE CARACTERE NULL EST ENVOYER
char	*ft_conv_c(t_asset asset, va_list ap)
{
	char	*str;
	char	c;
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
		w = va_arg(ap, wint_t);
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = (char)w;
		else
			str[--i] = (char)w;
	}
	else
	{
		c = va_arg(ap, int);
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = c;
		else
			str[--i] = c;
	}
	ft_putstr(str);
	return (str);
}
