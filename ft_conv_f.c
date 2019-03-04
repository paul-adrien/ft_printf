/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:43:02 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/01 11:30:24 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	sp_power(long nb, int power)
{
	if (power > 1)
		return (nb * sp_power(nb, (power - 1)));
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb);
}

static int	st_countsize(long n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_precision(t_asset asset, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (asset.precision < 16)
	{
		if (str[(i + asset.precision + 1)] > '4')
			str[i + asset.precision] = str[asset.precision + i] + ('b' - 'a');
		ft_bzero(str + i + asset.precision + 1, 16 - asset.precision);
	}
	else
	{
		if (asset.precision > 17)
			str[i + 17] = str[i + 17] + ('a' - 'b');
		asset.precision = asset.precision + i;
		while(i + 17 < asset.precision)
			str[i++ + 18] = '0';
		str[i + asset.precision] = '\0';
	}
	return (str);
}

static char		*ft_conv(char *str, long k, double n, int s)
{
	unsigned long	j;
	int				i;

	n = n - k;
	i = 0;
	j = n * sp_power(10, 17);
	while (i < 17)
	{
			str[i++] = (j % 10) + '0';
			j = j / 10;
	}
	str[i++] = '.';
	if (k == 0)
		str[i++] = '0';
	while (k != 0)
	{
		str[i++] = (k % 10) + '0';
		k = k / 10;
	}
	if (s == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}


static char		*ft_ftoa(double n)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0)
	{
		if (!(str = ft_strnew(19)))
			return (NULL);
		str[0] = '0';
		str[1] = '.';
		i = 0;
		while (i < 17)
			str[i++ + 2] = '0';
		return (str);
	}
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	if (!(str = ft_strnew(st_countsize(n) + 19)))
		return (NULL);
	str = ft_conv(str, n, n, i);
	return (str);
}

static char		*ft_preci_0(t_asset asset, long k)
{
	int		i;
	char	*str;

	i = st_countsize(k);
	if (!(str = ft_strnew(i + 2)))
		return (NULL);
	if (ft_strchr(asset.flags, '#') && k != 0)
		str[i] = '.';
	else if (ft_strchr(asset.flags, '#') && k == 0)
		str[i] = '.';
	if (k == 0)
		str[1] = '0';
	if (k < 0)
	{
		k = -k;
		str[0] = '-';
	}
	while (k != 0)
	{
		str[--i] = (k % 10) + '0';
		k = k / 10;
	}
	return (str);
}

char			*ft_conv_f(t_asset asset, va_list ap)
{
	char	*str;

	if (asset.precision == -1)
		asset.precision = 6;
	if (asset.precision == 0)
		str = ft_preci_0(asset, va_arg(ap, double));
	else
	{
		str = ft_ftoa(va_arg(ap, double));
		str = ft_precision(asset, str);
	}
	str = ft_width_f(asset, str, asset.width, ft_strlen(str));
	return (str);
}
