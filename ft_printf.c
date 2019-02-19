/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/19 16:40:11 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Commentaire propre
*/

#include "ft_printf.h"

/*
char 	*ft_findcomplexity(t_asset asset) // A MODIFIER POUR LA STRUCTURE // OLD ON SUPPRIME
{
	size_t	i;
	size_t	j;
	char 	*str;

	i = 1;
	j = 0;
	while (i <= 4)
	{
		if (asset[i][0])
			j++;
		i++;
	}
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = j + '0';
	return (str);
}*/

/*	if (signmode == 1)
 *	{
 *		if (ft_strchr(asset.flags, '-'))
		{
			if (ft_strchr(asset.flags, '+'))
				initial = sp_strnjoin("+", initial, ft_strlen(initial), 1);
			else if (ft_strchr(asset.flags, ' '))
				initial = sp_strnjoin(" ", initial, ft_strlen(initial), 1);
		}
		else if (ft_strchr(asset.flags, '+'))
			initial = sp_strnjoin("+", initial, ft_strlen(initial), 1);
	}

	// j'ai un nb positif, je demande le +, je n'ai pas de flag -, 
	// j'ai un 0 : je mettrai le + dans additional qu'importe la width
	// && (!(ft_strchr(asset.flags, '0') && asset.width > ft_strlen(initial))))
*/

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	char	*print;

	va_start(ap, format);
	tab = ft_formattotab(format);
	if (!(print = ft_dispatcher(tab, ap)))
	{
		ft_putstr("error de dispatcher\n");
		return (0); // CHECKER LES VALEURS DE RETOUR DE PRINTF
	}
	ft_putstr("R1 |"); // TEST
	ft_putstr(print);
	va_end(ap);
	return (0); // CHECKER LES VALEURS DE RETOUR DE PRINTF
}
