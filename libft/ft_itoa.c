/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:19:01 by pa                #+#    #+#             */
/*   Updated: 2018/11/29 10:52:04 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n <= 0)
	{
		nb = n * -1;
		i++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*str;

	i = ft_len(n);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	if (n <= 0)
	{
		nb = n * -1;
		if (n != 0)
			str[0] = '-';
		else
			str[0] = '0';
	}
	else
		nb = n;
	str[i] = '\0';
	while (nb > 0)
	{
		str[--i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
