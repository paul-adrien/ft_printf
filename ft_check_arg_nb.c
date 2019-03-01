/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:40:10 by eviana            #+#    #+#             */
/*   Updated: 2019/03/01 14:55:13 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_arg_nb(char **tab, va_list ap)
{
	va_list	ap2;
	int		type;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	va_copy(ap2, ap);
	while (tab[i])
	{
		type = ft_findtype(tab[i], 0);
		if (type && type != 7) // type = 8 pour futur %n /n
			j++;
		i++;
	}
//	if (!(print = (char**)malloc(sizeof(char*) * (i + 1))))
//		return (NULL);
//	print[i] = NULL;
	while (va_arg(ap2, int))
		k++;
	va_end(ap2);
	if (j != k) // Le vrai printf Segfault
		return (0);	
	return (1);
}
