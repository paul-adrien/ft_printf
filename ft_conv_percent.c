/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:18:00 by eviana            #+#    #+#             */
/*   Updated: 2019/02/25 16:32:15 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	u;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[n] != '\0')
		n++;
	while (i < (n / 2))
	{
		u = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = u;
		i++;
	}
	return (str);
}

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

// GERER LE CAS OU LE CARACTERE NULL EST ENVOYER
char	*ft_conv_percent(t_asset asset, va_list ap)
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
		w = (wint_t)'%';
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = (char)w;
		else
			str[--i] = (char)w;
	}
	else
	{
		c = '%';
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = c;
		else
			str[--i] = c;
	}
	ft_putstr(str);
	(void)ap;
	return (str);
}
