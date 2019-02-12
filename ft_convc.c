/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:04:48 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/11 18:18:32 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_s(t_asset asset, va_list *ap)
{
	char	*str;
	int		i;//nb total de cara qui sera afficher
	int		j;//nb de cara de ap a ecrire
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (str[i])
		i++;
	if (asset.precision >= 0 && asset.precision < i)
		j = asset.precision;
	if (i < asset.width)
		str = strnew(asset.width);
	else
		str = strnew(i - j);
	while
}

char	*ft_conv_c(t_asset asset, va_list *ap)
{
	char	*str;
	char	k;
	wint_t	w;
	int		i;
	int		j;

	j = 0;
	i = asset.width;
	if (i < 0)
		i == 0;
	str = strnew(i + 2);
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
		k = va_arg(ap, char);
		while (j < i)
			str[j++] = ' ';
		if (ft_strchr(asset.flags, '-') || i == 0)
			str[0] = k;
		else
			str[--i] = k;
	}
	return (str);

