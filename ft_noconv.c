/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:16:43 by eviana            #+#    #+#             */
/*   Updated: 2019/03/04 10:03:21 by eviana           ###   ########.fr       */
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
	(void)ap;
	return (ft_strnew(0));
}
