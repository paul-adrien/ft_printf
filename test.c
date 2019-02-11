/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:13:04 by eviana            #+#    #+#             */
/*   Updated: 2019/02/09 15:26:48 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_stocknbr(int n)
{
	char            *str;
	long int        newnb;
	size_t          i;

	i = 0;
	newnb = n;
	while (n)
	{
		i++;
		n = n / 10;
	}
	if (!(str = ft_strnew(i + (newnb < 0 ? 1 : 0))))
		return (NULL);
	if (newnb < 0)
	{
		i++;
		str[0] = '-';
		newnb = -newnb;
	}
	while (newnb)
	{
		str[i - 1] = newnb % 10 + '0';
		newnb = newnb / 10;
		i--;
	}
	return (str);
}

int		main(int ac, char **av)
{
	ft_putstr(ft_stocknbr(atoi(av[1])));

	(void)ac;
	return (0);
}
