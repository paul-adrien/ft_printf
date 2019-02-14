/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:43:02 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/14 20:26:12 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_recursive_power(int nb, int power)
{
	if (power > 1)
		return (nb * ft_recursive_power(nb, (power - 1)));
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb);
}*/

static int	st_countsize(int n)
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

static char		*ft_ftoa(double n, int p)
{
	int		i;
	int		j;
	long	k;
	char	*str;

	j = 0;
	i = st_countsize(n * ft_recursive_power(10, p)) + 1;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '.';
		while (j < p)
			str[j++ + 2] = '0';
		return (str);
	}
	k = n * ft_recursive_power(10, p);
	while (k != 0)
	{
		str[i - 1] = (k % 10) + '0';
		k = k / 10;
		i--;
		j++;
		if (j == p)
			str[i-- - 1] = '.';
	}
	return (str);
}

char	*ft_conv_f(t_asset asset, va_list ap)
{
	char	*str;
	char	*str2;
	int		i;

	i = asset.precision;
	if (asset.precision == -1)
		i = 6;
	if (asset.precision == 0)
		i = 1;
	if (asset.precision >= 10)
	{
		str = ft_ftoa(va_arg(ap, double), 9);
		str2 = ft_strnew(st_countsize(//rajouter quand on veut plus que 10 
					//de precision pour rajouter des zeros
	else
		str = ft_ftoa(va_arg(ap, double), i);
	return (str);
}
