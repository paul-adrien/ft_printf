/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:16:43 by eviana            #+#    #+#             */
/*   Updated: 2019/02/26 12:34:44 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_noconv(t_asset asset, va_list ap)
{
	char *str;

	if (asset.copy && asset.copy[0] != '%')
	{
		if (!(str = (ft_strsub(asset.copy, 0, ft_strlen(asset.copy)))))
			return (NULL);
		return (str);
	}
	/*while (asset.copy[i] && asset.copy[i] != 'Z')
		i++;
	if (asset.copy[i] == 'Z')
	{
		if (!(str = ft_strsub(asset.copy, i, ft_strlen(asset.copy + i))))
			return (NULL);
		str = ft_memset(str, 90, 1);
		return (str);
	}*/
	(void)ap;
	return (ft_strnew(0));
}
