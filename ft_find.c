/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:49:55 by eviana            #+#    #+#             */
/*   Updated: 2019/02/25 17:34:51 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_findflags(char *tab, size_t *i)
{
	char	*str;

	*i = *i + 1;
	while (tab[*i] && (tab[*i] == '-' || tab[*i] == '+' || tab[*i] == ' ' || tab[*i] == '0' || tab[*i] == '#'))
		*i = *i + 1;
	if (!(str = ft_strsub(tab, 1, *i - 1)))
		return (NULL);
	return (str);
}

size_t	ft_findwidth(char *tab, size_t *i)
{
	size_t	n;

	n = 0;
	while (tab[*i] && (tab[*i] >= '0' && tab[*i] <= '9'))
	{
		n = 10 * n + (tab[*i] - '0');
		*i = *i + 1;
	}
	return (n);
}

int		ft_findprecision(char *tab, size_t *i)
{
	int	n;

	n = 0;
	if (tab[*i] && (tab[*i] == '.'))
	{
		*i = *i + 1;
		while (tab[*i] && tab[*i] >= '0' && tab[*i] <= '9')
		{
			n = 10 * n + (tab[*i] - '0');
			*i = *i + 1;
		}
	}
	else
		return (-1); // Pour condition de non prise en charge dans la construction de la conversion
	return (n);
}

int		ft_findlength(char *tab, size_t *i)
{
	if (tab[*i] && tab[*i] == 'l')
		return ((tab[*i + 1] && tab[*i + 1] == 'l' ? 2 : 1));
	else if (tab[*i] && tab[*i] == 'h')
		return ((tab[*i + 1] && tab[*i + 1] == 'h' ? 4 : 3));
	return (0);
}

int		ft_findtype(char *tab, size_t i) // Pour identifier la conversion
{
	int	n;

	n = 0;
	if (!tab)
		return (-1);
	if (tab[0] == '%') //&& (tab[1] && tab[1] != '%')) // a verifier pour le %%
	{
		if (i == 0)
		{
			while (tab[i])
				i++;
			i--;
		}
		(tab[i] == 'd' || tab[i] == 'i' ? n = 1 : 0);
		(tab[i] == 'o' ? n = 21 : 0);
	  	(tab[i] == 'u' ? n = 22 : 0);
		(tab[i] == 'x' ? n = 23 : 0);
		(tab[i] == 'X' ? n = 24 : 0);
		(tab[i] == 'c' ? n = 3 : 0); // a verifier pour le %%
		(tab[i] == 's' ? n = 4 : 0);
		(tab[i] == 'p' ? n = 5 : 0);
		(tab[i] == 'f' ? n = 6 : 0);
		(tab[i] == '%' ? n = 7 : 0);
		return (n);
	}
	return (n);
}
