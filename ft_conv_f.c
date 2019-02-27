/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:43:02 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/27 17:17:34 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	sp_sizel(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static long	sp_power(long nb, long power)
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

static char		*ft_conv(char *str, long k, int p, int i)
{
	if ((k % 10) > 4 && (p  + i < 16))
		k = (k / 10) + 1;
	else
		k = k / 10;
	if (i == 0)
		i = 17;
	else
		i = 16;
	while (k != 0)
	{
		str[i--] = (k % 10) + '0';
		k = k / 10;
		if (--p == 0)
		{
			str[i--] = '.';
			if (k < 1)
				str[i] = '0';
		}
	}
	return (str);
}

char			*st_str_0(char *str, int p, int i)
{
	char	*str2;
	int		j;
	int		k;

	if (i == 0)
		i = 1;
	k = ft_strlen(str) + p - (17 - i);
	j = -1;
	str2 = ft_strnew(k);
	while (str[++j])
		str2[j] = str[j];
	while (j <= k)
		str2[j++] = '0';
	return (str2);
}

static char		*ft_ftoa(double n, int p)
{
	int				i;
	//unsigned long	k;
	char			*str;

	i = st_countsize(n * sp_power(10, p)) + 1;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n < 1 && n > -1)
		i++;
	if (n == 0)
	{
		if (!(str = ft_strnew(2 + p)))
			return (NULL);
		str[0] = '0';
		str[1] = '.';
		i = 0;
		while (i < p)
			str[i++ + 2] = '0';
		return (str);
	}
	if (p + sp_sizel(n) <= 17)
		str = ft_conv(str, n * sp_power(10, p + 1), p, i - 1);
	else
		str = st_str_0(ft_conv(str, n * sp_power(10, 17 - sp_sizel(n)), 16 - sp_sizel(n), sp_sizel(n)), p, sp_sizel(n));
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
		str[1] = '.';
	if (k == 0)
		str[0] = '0';
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

char			*ft_width(t_asset asset, char *str, int i/*width*/, int j/*strlen*/)
{
	char	*str2;
	int		k;
	int		n;

	n = 0;
	k = -1;
	if (i > j)
	{
		if (!(str2 = ft_strnew(i + 1)))
			return (NULL);
	}
	else
	{
		if(!(str2 = ft_strnew(j + 1)))
			return (NULL);
		i = j;
	}
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		if (ft_strchr(asset.flags, '+'))
			str2[n++] = '+';
		else if (ft_strchr(asset.flags, ' '))
			str2[n++] = ' ';
		while (++k < j)
			str2[k + n] = str[k];
		while (k + n < i)
			str2[k++ + n] = ' ';
	}
	else
	{
		n = i - j;
		k = i;
		while (--j >= 0)
			str2[--k] = str[j];
		while (k > 0)
		{
			if (ft_strchr(asset.flags, '0'))
				str2[--k] = '0';
			else
				str2[--k] = ' ';
		}
		if (ft_strchr(asset.flags, '+') && ft_strchr(asset.flags, '0'))
			str2[0] = '+';
		else if (ft_strchr(asset.flags, '+'))
			str2[n - 1] = '+';
		if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '0') &&
				!ft_strchr(asset.flags, '+'))
			str2[0] = ' ';
	}
	return (str2);
}

char			*ft_conv_f(t_asset asset, va_list ap)
{
	char	*str;
	size_t	i;

	i = asset.precision;
	if (asset.precision == -1)
		i = 6;
	if (asset.precision == 0)
		str = ft_preci_0(asset, va_arg(ap, double));
	else
		str = ft_ftoa(va_arg(ap, double), i);
	str = ft_width(asset, str, asset.width, ft_strlen(str));
	return (str);
}
