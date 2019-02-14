/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:31:38 by eviana            #+#    #+#             */
/*   Updated: 2019/02/14 19:09:55 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_ltoa(long n)
{
	long	newnb;
	int		i;
	char	*str;

	newnb = n;
	i = st_countsize(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		newnb = -newnb;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	while (newnb != 0)
	{
		str[i - 1] = (newnb % 10) + '0';
		newnb = newnb / 10;
		i--;
	}
	return (str);
}
