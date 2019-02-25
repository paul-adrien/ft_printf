/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:17:51 by eviana            #+#    #+#             */
/*   Updated: 2019/02/25 15:09:15 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	sp_power(long long nb, long long power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb * ft_power(nb, power - 1));
}

static int			ft_base_analysis(char *base)
{
	int	i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static long long	sp_atoll_base(char *str, char *base)
{
	long long	res;
	size_t		str_len;
	size_t		base_len;
	size_t		i;
	size_t		j;

	i = 0;
	res = 0;
	if (str[0] == '-' || str[0] == '+')
		str = ft_strncpy(str, str + 1, ft_strlen(str));
	str_len = ft_strlen(str);
	base_len = ft_strlen(base);
	while (str_len > 0)
	{
		j = 0;
		while (base[j] && base[j] != str[str_len - 1])
			j++;
		if (j == base_len)
			return (-1);
		res = res + (j * sp_power(base_len, i));
		i++;
		str_len--;
	}
	return (res);
}

static int			sp_strlen_base(long long nbr, size_t base)
{
	int res;

	res = 0;
	if (base)
	{
		while (nbr)
		{
			nbr = nbr / base;
			res++;
		}
	}
	return (res);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	long long	decimal_nb;
	size_t		base_to_len;
	size_t		str_len;
	int			is_neg;

	is_neg = (nbr[0] == '-' ? 1 : 0);
	if (!(ft_base_analysis(base_from)) || !(ft_base_analysis(base_to)) ||
			!nbr || (decimal_nb = sp_atoll_base(nbr, base_from)) == -1)
		return (0);
	base_to_len = ft_strlen(base_to);
	str_len = sp_strlen_base(decimal_nb, base_to_len) + is_neg;
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[0] = (decimal_nb == 0 ? base_to[0] : str[0]);
	while (decimal_nb != 0)
	{
		str[str_len - 1] = base_to[decimal_nb % base_to_len];
		decimal_nb = decimal_nb / base_to_len;
		str_len--;
	}
	str[0] = (is_neg == 1 ? '-' : str[0]);
	return (str);
}
