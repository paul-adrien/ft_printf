/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:12:01 by pa                #+#    #+#             */
/*   Updated: 2018/11/26 22:50:34 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoilen(const char *str, int k)
{
	int j;
	int i;

	j = 0;
	i = k;
	while (str[i] != '\0' && (str[i] != '\t' && str[i] != '\f' &&
				str[i] != '\n' && str[i] != '\r' && str[i] != '\v' &&
				str[i] != ' '))
	{
		i++;
		j++;
	}
	return (j);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				c;
	unsigned int	m;
	int				n;

	i = 0;
	m = 0;
	c = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (ft_atoilen(str, i) > 20 && str[i] == '-')
		return (0);
	if (ft_atoilen(str, i) > 19 && str[i] != '-')
		return (-1);
	if (str[i] == '-')
		c = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
		m = m * 10 + (str[i++] - '0');
	n = m * c;
	return (n);
}
