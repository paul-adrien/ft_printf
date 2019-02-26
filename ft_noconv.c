/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:16:43 by eviana            #+#    #+#             */
/*   Updated: 2019/02/26 11:10:31 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_noconv(t_asset asset, va_list ap)
{
	char *str;
	int i;

	i = 0;
	if (asset.copy[0] != '%')
	{
		if (!(str = (ft_strsub(asset.copy, 0, ft_strlen(asset.copy)))))
			return (NULL);
		return (str);
	}
	while (asset.copy[i] != 'Z')
		i++;
	if (asset.copy[i - 1] == 'Z')
	{
		if (!(str = ft_strsub(asset.copy, i, ft_strlen(asset.copy + i))))
			return (NULL);
		str = ft_memset(str, 90, 1);
	}
	(void)ap;
	return (ft_strnew(0));
}
