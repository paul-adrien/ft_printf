/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:49:55 by eviana            #+#    #+#             */
/*   Updated: 2019/02/27 14:18:33 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_findflags(char *tab, size_t i)
{
	char	*tmp;
	char	*str;
	size_t	j;

	j = 0;
	str = ft_strnew(0);
	tmp = ft_strnew(1);
	while (tab[++i])
	{
		if (tab[i] == '-' || tab[i] == '+' || tab[i] == ' ' || tab[i] == '#')
		{
			tmp[0] = tab[i];
			str = ft_strjoin(str, tmp);
		}
		if (tab[i] == '0' && (tab[i - 1] < '0' || tab[i - 1] > '9') &&
				tab[i - 1] != '.')
			if (!(str = ft_strjoin(str, ft_strsub(tab, i, 1))))
				return (NULL);
	}
	free(tmp);
	return (str);
}

size_t	ft_findwidth(char *tab, size_t i)
{
	size_t	n;
	size_t	j;

	n = 0;
	while (tab[++i])
		if (tab[i] <= '9' && tab[i] > '0')
		{
			j = 1;
			while (tab[i - j] == '0')
				j++;
			if ((tab[i - j] != '.' && (tab[i - j] < '0' || tab[i - j] > '9')) ||
					tab[i - j] == '%')
			{
				n = 0;
				while (tab[i] <= '9' && tab[i] >= '0')
					n = 10 * n + (tab[i++] - '0');
			}
		}
	return (n);
}

int		ft_findprecision(char *tab, size_t i)
{
	int		n;

	n = -1;
	while (tab[++i])
		if (tab[i] == '.')
		{
			n = 0;
			while (tab[i + 1] && tab[i + 1] >= '0' && tab[i + 1] <= '9')
				n = 10 * n + (tab[i++ + 1] - '0');
		}
	return (n);
}

int		ft_findlength(char *tab, size_t i)
{
	while (tab[++i + 1])
	{
		if (tab[i] && tab[i] == 'l')
			return ((tab[i + 1] && tab[i + 1] == 'l' ? 2 : 1));
		else if (tab[i] && tab[i] == 'h')
			return ((tab[i + 1] && tab[i + 1] == 'h' ? 4 : 3));
	}
	return (0);
}

int		ft_findtype(char *tab, size_t i) // Pour identifier la conversion
{
	int	n;

	n = 0;
	if (!tab)
		return (-1);
	if (tab[i] == '%') //&& (tab[1] && tab[1] != '%')) // a verifier pour le %%
	{
		while (tab[i])
			i++;
		i--;
		(tab[i] == 'd' || tab[i] == 'i' ? n = 1 : 0);
		(tab[i] == 'o' ? n = 21 : 0);
	  	(tab[i] == 'u' ? n = 22 : 0);
		(tab[i] == 'x' ? n = 23 : 0);
		(tab[i] == 'X' ? n = 24 : 0);
		(tab[i] == 'c' ? n = 3 : 0); // a verifier pour le %%
		(tab[i] == 's' ? n = 4 : 0);
		(tab[i] == 'p' ? n = 5 : 0);
		(tab[i] == 'f' ? n = 6 : 0);
		(tab[i] == '%' && i != 0 ? n = 7 : 0);
		return (n);
	}
	return (n);
}
